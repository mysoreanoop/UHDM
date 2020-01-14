/*
 Do not modify, auto-generated by model_gen.tcl

 Copyright 2019 Alain Dargelas

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
 * File:   variables.h
 * Author:
 *
 * Created on December 14, 2019, 10:03 PM
 */

#ifndef VARIABLES_H
#define VARIABLES_H

namespace UHDM {

  class variables : public BaseClass {
  public:
    // Implicit constructor used to initialize all members,
    // comment: variables();
    ~variables()  {}
    
    bool get_vpiArrayMember() const { return vpiArrayMember_; }

    bool set_vpiArrayMember(bool data) { vpiArrayMember_ = data; return true;}

    std::string get_vpiName() const { return SymbolFactory::getSymbol(vpiName_); }

    bool set_vpiName(std::string data) { vpiName_ = SymbolFactory::make(data); return true; }

    std::string get_vpiFullName() const { return SymbolFactory::getSymbol(vpiFullName_); }

    bool set_vpiFullName(std::string data) { vpiFullName_ = SymbolFactory::make(data); return true; }

    bool get_vpiSigned() const { return vpiSigned_; }

    bool set_vpiSigned(bool data) { vpiSigned_ = data; return true;}

    int get_vpiSize() const { return vpiSize_; }

    bool set_vpiSize(int data) { vpiSize_ = data; return true;}

    bool get_vpiAutomatic() const { return vpiAutomatic_; }

    bool set_vpiAutomatic(bool data) { vpiAutomatic_ = data; return true;}

    int get_vpiAllocScheme() const { return vpiAllocScheme_; }

    bool set_vpiAllocScheme(int data) { vpiAllocScheme_ = data; return true;}

    bool get_vpiConstantVariable() const { return vpiConstantVariable_; }

    bool set_vpiConstantVariable(bool data) { vpiConstantVariable_ = data; return true;}

    bool get_vpiIsRandomized() const { return vpiIsRandomized_; }

    bool set_vpiIsRandomized(bool data) { vpiIsRandomized_ = data; return true;}

    int get_vpiRandType() const { return vpiRandType_; }

    bool set_vpiRandType(int data) { vpiRandType_ = data; return true;}

    bool get_vpiStructUnionMember() const { return vpiStructUnionMember_; }

    bool set_vpiStructUnionMember(bool data) { vpiStructUnionMember_ = data; return true;}

    bool get_vpiScalar() const { return vpiScalar_; }

    bool set_vpiScalar(bool data) { vpiScalar_ = data; return true;}

    int get_vpiVisibility() const { return vpiVisibility_; }

    bool set_vpiVisibility(int data) { vpiVisibility_ = data; return true;}

    bool get_vpiVector() const { return vpiVector_; }

    bool set_vpiVector(bool data) { vpiVector_ = data; return true;}

    VectorOfports* get_ports() const { return ports_; }

    bool set_ports(VectorOfports* data) { ports_ = data; return true;}

    VectorOfvariable_drivers* get_variable_drivers() const { return variable_drivers_; }

    bool set_variable_drivers(VectorOfvariable_drivers* data) { variable_drivers_ = data; return true;}

    VectorOfvariable_loads* get_variable_loads() const { return variable_loads_; }

    bool set_variable_loads(VectorOfvariable_loads* data) { variable_loads_ = data; return true;}

    typespec* get_typespec() const { return typespec_; }

    bool set_typespec(typespec* data) { typespec_ = data; return true;}

    instance* get_instance() const { return instance_; }

    bool set_instance(instance* data) { instance_ = data; return true;}

    scope* get_scope() const { return scope_; }

    bool set_scope(scope* data) { scope_ = data; return true;}

    expr* get_expr() const { return expr_; }

    bool set_expr(expr* data) { expr_ = data; return true;}

    VectorOfexpr* get_indexes() const { return indexes_; }

    bool set_indexes(VectorOfexpr* data) { indexes_ = data; return true;}

    VectorOfprim_term* get_prim_terms() const { return prim_terms_; }

    bool set_prim_terms(VectorOfprim_term* data) { prim_terms_ = data; return true;}

    VectorOfcont_assign* get_cont_assigns() const { return cont_assigns_; }

    bool set_cont_assigns(VectorOfcont_assign* data) { cont_assigns_ = data; return true;}

    path_term* get_path_term() const { return path_term_; }

    bool set_path_term(path_term* data) { path_term_ = data; return true;}

    tchk_term* get_tchk_term() const { return tchk_term_; }

    bool set_tchk_term(tchk_term* data) { tchk_term_ = data; return true;}

    module* get_module() const { return module_; }

    bool set_module(module* data) { module_ = data; return true;}

    virtual unsigned int getUhdmType() { return uhdmvariables; }   
  private:
    
    bool vpiArrayMember_;

    unsigned int vpiName_;

    unsigned int vpiFullName_;

    bool vpiSigned_;

    int vpiSize_;

    bool vpiAutomatic_;

    int vpiAllocScheme_;

    bool vpiConstantVariable_;

    bool vpiIsRandomized_;

    int vpiRandType_;

    bool vpiStructUnionMember_;

    bool vpiScalar_;

    int vpiVisibility_;

    bool vpiVector_;

    VectorOfports* ports_;

    VectorOfvariable_drivers* variable_drivers_;

    VectorOfvariable_loads* variable_loads_;

    typespec* typespec_;

    instance* instance_;

    scope* scope_;

    expr* expr_;

    VectorOfexpr* indexes_;

    VectorOfprim_term* prim_terms_;

    VectorOfcont_assign* cont_assigns_;

    path_term* path_term_;

    tchk_term* tchk_term_;

    module* module_;

  };

  class variablesFactory {
  friend Serializer;
  public:
  static variables* make() {
    variables* obj = new variables();
    objects_.push_back(obj);
    return obj;
  }
  private:
    static std::vector<variables*> objects_;
  };
 	      
  class VectorOfvariablesFactory {
  friend Serializer;
  public:
  static std::vector<variables*>* make() {
    std::vector<variables*>* obj = new std::vector<variables*>();
    objects_.push_back(obj);
    return obj;
  }
  private:
  static std::vector<std::vector<variables*>*> objects_;
  };

};

#endif

