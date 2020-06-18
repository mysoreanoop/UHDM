/*
 Do not modify, auto-generated by model_gen.tcl

 Copyright 2019-2020 Alain Dargelas

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

/*
 * File:   vpi_visitor.cpp
 * Author: alain
 *
 * Created on December 14, 2019, 10:03 PM
 */

#include <string.h>

#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#ifdef STANDARD_VPI

#include <sv_vpi_user.h>

// C++ 98 is default in Simulators compilers
typedef std::set<vpiHandle> VisitedContainer;
// Missing defines from vpi_user.h, sv_vpi_user.h, They are no-op in the Standard implementation.
#define uhdmdesign 2569
#define uhdmallPackages 2570
#define uhdmallClasses 2571
#define uhdmallInterfaces 2572
#define uhdmallUdps 2573
#define uhdmallPrograms 2574
#define uhdmallModules 2575
#define uhdmtopModules 2576
#define vpiDesign 3000
#define vpiInterfaceTypespec 3001
#define vpiNets 3002
#define vpiSimpleExpr 3003
#define vpiParameters 3004
#define vpiSequenceExpr 3005
#define vpiUnsupportedStmt 4000
#define vpiUnsupportedExpr 4001

#else

#include "include/sv_vpi_user.h"
#include "include/vhpi_user.h"
#include "headers/uhdm_types.h"
#include "headers/containers.h"
#include "headers/vpi_uhdm.h"
#include "headers/uhdm.h"
#include "headers/Serializer.h"
typedef  std::set<const UHDM::BaseClass*> VisitedContainer;

#endif

// UHDM implementation redefine these
#ifndef vpiVarBit
  #define vpiVarBit          vpiRegBit 
  #define vpiLogicVar        vpiReg
  #define vpiArrayVar        vpiRegArray
#endif


namespace UHDM {

static std::string visit_value(s_vpi_value* value) {
  if (value == nullptr)
    return "";
  switch (value->format) {
  case vpiIntVal: {
    return std::string(std::string("|INT:") + std::to_string(value->value.integer) + "\n");
    break;
  }
  case vpiStringVal: {
    const char* s = (const char*) value->value.str;
    return std::string(std::string("|STRING:") + std::string(s) + "\n");
    break;
  }
  case vpiBinStrVal: {
    const char* s = (const char*) value->value.str;
    return std::string(std::string("|BIN:") + std::string(s) + "\n");
    break;
  }
  case vpiHexStrVal: {
    const char* s = (const char*) value->value.str;
    return std::string(std::string("|HEX:") + std::string(s) + "\n");
    break;
  }
  case vpiOctStrVal: {
    const char* s = (const char*) value->value.str;
    return std::string(std::string("|OCT:") + std::string(s) + "\n");
    break;
  }
  case vpiRealVal: {
    return std::string(std::string("|REAL:") + std::to_string(value->value.real) + "\n");
    break;
  }
  case vpiScalarVal: {
    return std::string(std::string("|SCAL:") + std::to_string(value->value.scalar) + "\n");
    break;
  }
  default:
    break;
  }
  return "";
}

static std::string visit_delays(s_vpi_delay* delay) {
  if (delay == nullptr)
    return "";
  switch (delay->time_type) {
  case vpiScaledRealTime: {
    return std::string(std::string("|#") + std::to_string(delay->da[0].low) + "\n");
    break;
  }
  default:
    break;
  }
  return "";
}

static std::ostream &stream_indent(std::ostream &out, int indent) {
  out << std::string(indent, ' ');
  return out;
}

static void visit_object (vpiHandle obj_h, int indent, const char *relation, VisitedContainer* visited, std::ostream& out) {

#ifdef STANDARD_VPI
  
  static int kLevelIndent = 2;
  const bool alreadyVisited = visited->find(obj_h) != visited->end();
  visited->insert(obj_h);

#else
  
  static constexpr int kLevelIndent = 2;
  const uhdm_handle* const handle = (const uhdm_handle*) obj_h;
  const BaseClass* const object = (const BaseClass*) handle->object;
  const bool alreadyVisited = visited->find(object) != visited->end();
  visited->insert(object);
  
#endif
  
  unsigned int subobject_indent = indent + kLevelIndent;
  const unsigned int objectType = vpi_get(vpiType, obj_h);
 
  {
    std::string hspaces;
    std::string rspaces;
    if (indent >= kLevelIndent) {
      for (int i = 0; i < indent -2 ; i++) {
        hspaces += " ";
      }
      rspaces = hspaces + "|";
      hspaces += "\\_";
    }

    if (strlen(relation) != 0) {
      out << rspaces << relation << ":\n";
    }
    
#ifdef STANDARD_VPI

    out << hspaces << "vpiType: " << vpi_get(vpiType, obj_h) << ": ";

#else

    out << hspaces << UHDM::VpiTypeName(obj_h) << ": ";

#endif
    
    bool needs_separator = false;
    if (const char* s = vpi_get_str(vpiDefName, obj_h)) {  // defName
      out << s;
      needs_separator = true;
    }
    if (const char* s = vpi_get_str(vpiName, obj_h)) {   // objectName
      if (needs_separator) out << " ";
      out << "(" << s << ")";  // objectName
    }

#ifndef STANDARD_VPI

    out << ", id:" << object->UhdmId();

#endif    

    if (objectType == vpiModule || objectType == vpiProgram || objectType == vpiClassDefn || objectType == vpiPackage ||
        objectType == vpiInterface || objectType == vpiUdp) {
      if (const char* s = vpi_get_str(vpiFile, obj_h))
        out << ", file:" << s;  // fileName
    }
    if (int l = vpi_get(vpiLineNo, obj_h)) {
      out << ", line:" << l;
    }
    if (vpiHandle par = vpi_handle(vpiParent, obj_h)) {
      if (const char* parentName = vpi_get_str(vpiName, par)) {
        out << ", parent:" << parentName;
      }
      vpi_free_object(par);
    }
    out << "\n";
  }

  if (alreadyVisited) {
    return;
  }
  if (strcmp(relation, "vpiParent") == 0) {
    return;
  }
<OBJECT_VISITORS>
}

// Public interface
void visit_designs (const std::vector<vpiHandle>& designs, std::ostream &out) {
  for (auto design : designs) {
    VisitedContainer visited;
    visit_object(design, 0, "", &visited, out);
  }
}

std::string visit_designs (const std::vector<vpiHandle>& designs) {
  std::stringstream out;
  visit_designs(designs, out);
  return out.str();
}

};


static std::stringstream the_output;

extern "C" { 
  void vpi_decompiler (vpiHandle design) {
    std::vector<vpiHandle> designs;
    designs.push_back(design);
    UHDM::visit_designs(designs, the_output);
    std::cout << the_output.str().c_str() << std::endl;
  }
}
