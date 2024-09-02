// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vregister_tree_tb.h for the primary calling header

#ifndef VERILATED_VREGISTER_TREE_TB___024ROOT_H_
#define VERILATED_VREGISTER_TREE_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_threads.h"
#include "verilated_timing.h"


class Vregister_tree_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vregister_tree_tb___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VlUnpacked<IData/*31:0*/, 15> register_tree_tb__DOT__dut__DOT__tree;
        CData/*0:0*/ register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__parent_less_than_right;
        CData/*0:0*/ register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__parent_less_than_left;
        CData/*0:0*/ register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__parent_less_than_left;
        CData/*0:0*/ register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__left_greater_than_right;
        CData/*0:0*/ register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__left_greater_than_right;
        CData/*0:0*/ register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__parent_less_than_right;
        CData/*0:0*/ register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__parent_less_than_right;
        CData/*0:0*/ register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__parent_less_than_left;
        CData/*0:0*/ register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__parent_less_than_left;
        CData/*0:0*/ register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__left_greater_than_right;
        CData/*0:0*/ register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__left_greater_than_right;
        CData/*0:0*/ register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__parent_less_than_right;
        CData/*0:0*/ register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__parent_less_than_right;
        CData/*0:0*/ register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__parent_less_than_left;
        CData/*0:0*/ register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__parent_less_than_left;
        CData/*0:0*/ register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__left_greater_than_right;
        CData/*0:0*/ register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__left_greater_than_right;
        CData/*0:0*/ register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__parent_less_than_right;
        CData/*0:0*/ register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__parent_less_than_left;
        CData/*0:0*/ register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__parent_less_than_right;
        CData/*0:0*/ register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__left_greater_than_right;
        VlUnpacked<CData/*0:0*/, 8> __Vm_traceActivity;
        VlUnpacked<IData/*31:0*/, 7> register_tree_tb__DOT__dut__DOT__new_right_child;
        IData/*31:0*/ register_tree_tb__DOT__dut__DOT__unnamedblk2__DOT__k;
        IData/*31:0*/ register_tree_tb__DOT__dut__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j;
        IData/*31:0*/ register_tree_tb__DOT__dut__DOT__unnamedblk4__DOT__m;
        IData/*31:0*/ register_tree_tb__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__n;
        IData/*31:0*/ register_tree_tb__DOT__dut__DOT____Vlvbound_hfb5ebc9c__0;
        IData/*31:0*/ register_tree_tb__DOT__dut__DOT____Vlvbound_h07d53320__0;
        IData/*31:0*/ register_tree_tb__DOT__dut__DOT____Vlvbound_h07d501a4__0;
        IData/*31:0*/ register_tree_tb__DOT__dut__DOT____Vlvbound_ha43e4694__0;
        IData/*31:0*/ register_tree_tb__DOT__dut__DOT____Vlvbound_he77e3845__0;
        IData/*31:0*/ register_tree_tb__DOT__dut__DOT____Vlvbound_he77e065b__0;
        VlUnpacked<IData/*31:0*/, 7> register_tree_tb__DOT__dut__DOT__new_left_child;
        VlUnpacked<IData/*31:0*/, 7> register_tree_tb__DOT__dut__DOT__new_parent;
        CData/*0:0*/ register_tree_tb__DOT__replace;
        IData/*31:0*/ register_tree_tb__DOT__new_item;
        IData/*31:0*/ register_tree_tb__DOT__top_item;
        IData/*31:0*/ __VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v0;
        IData/*31:0*/ __VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v1;
        IData/*31:0*/ __VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v2;
        IData/*31:0*/ __VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v3;
        IData/*31:0*/ __VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v4;
        IData/*31:0*/ __VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v5;
        IData/*31:0*/ __VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v6;
        IData/*31:0*/ __VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v7;
        IData/*31:0*/ __VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v8;
        IData/*31:0*/ __VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v9;
        IData/*31:0*/ __VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v10;
        IData/*31:0*/ __VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v11;
        IData/*31:0*/ __VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v12;
        IData/*31:0*/ __VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v13;
        IData/*31:0*/ __VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v14;
        IData/*31:0*/ __VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v15;
        IData/*31:0*/ __VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v16;
        IData/*31:0*/ __VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v17;
        IData/*31:0*/ __VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v18;
        IData/*31:0*/ __VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v19;
        IData/*31:0*/ __VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v20;
        IData/*31:0*/ __VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v21;
        CData/*0:0*/ __VdlySet__register_tree_tb__DOT__dut__DOT__tree__v21;
        CData/*0:0*/ __VdlySet__register_tree_tb__DOT__dut__DOT__tree__v20;
        CData/*0:0*/ __VdlySet__register_tree_tb__DOT__dut__DOT__tree__v19;
    };
    struct {
        CData/*0:0*/ __VdlySet__register_tree_tb__DOT__dut__DOT__tree__v18;
        CData/*0:0*/ __VdlySet__register_tree_tb__DOT__dut__DOT__tree__v17;
        CData/*0:0*/ __VdlySet__register_tree_tb__DOT__dut__DOT__tree__v16;
        CData/*0:0*/ __VdlySet__register_tree_tb__DOT__dut__DOT__tree__v15;
        CData/*0:0*/ __VdlySet__register_tree_tb__DOT__dut__DOT__tree__v14;
        CData/*0:0*/ __VdlySet__register_tree_tb__DOT__dut__DOT__tree__v13;
        CData/*0:0*/ __VdlySet__register_tree_tb__DOT__dut__DOT__tree__v12;
        CData/*0:0*/ __VdlySet__register_tree_tb__DOT__dut__DOT__tree__v11;
        CData/*0:0*/ __VdlySet__register_tree_tb__DOT__dut__DOT__tree__v10;
        CData/*0:0*/ __VdlySet__register_tree_tb__DOT__dut__DOT__tree__v9;
        CData/*0:0*/ __VdlySet__register_tree_tb__DOT__dut__DOT__tree__v8;
        CData/*0:0*/ __VdlySet__register_tree_tb__DOT__dut__DOT__tree__v7;
        CData/*0:0*/ __VdlySet__register_tree_tb__DOT__dut__DOT__tree__v6;
        CData/*0:0*/ __VdlySet__register_tree_tb__DOT__dut__DOT__tree__v5;
        CData/*0:0*/ __VdlySet__register_tree_tb__DOT__dut__DOT__tree__v4;
        CData/*0:0*/ __VdlySet__register_tree_tb__DOT__dut__DOT__tree__v3;
        CData/*0:0*/ __VdlySet__register_tree_tb__DOT__dut__DOT__tree__v2;
        CData/*0:0*/ __VdlySet__register_tree_tb__DOT__dut__DOT__tree__v1;
        CData/*0:0*/ __VdlySet__register_tree_tb__DOT__dut__DOT__tree__v0;
        CData/*0:0*/ register_tree_tb__DOT__clk;
        CData/*0:0*/ __VdlyVal__register_tree_tb__DOT__clk__v0;
        CData/*0:0*/ __VdlySet__register_tree_tb__DOT__clk__v0;
        CData/*0:0*/ register_tree_tb__DOT__dut__DOT__level_indicator;
        CData/*0:0*/ __Vdly__register_tree_tb__DOT__dut__DOT__level_indicator;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__register_tree_tb__DOT__clk__0;
        CData/*0:0*/ __VactContinue;
        IData/*31:0*/ register_tree_tb__DOT__unnamedblk1__DOT__i;
        IData/*31:0*/ register_tree_tb__DOT__unnamedblk2__DOT__i;
        IData/*31:0*/ register_tree_tb__DOT__unnamedblk3__DOT__i;
        IData/*31:0*/ register_tree_tb__DOT__unnamedblk4__DOT__i;
        IData/*31:0*/ register_tree_tb__DOT__unnamedblk5__DOT__i;
        IData/*31:0*/ register_tree_tb__DOT__dut__DOT__unnamedblk1__DOT__j;
        IData/*31:0*/ __VactIterCount;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_hf71ee19c__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;
    VlMTaskVertex __Vm_mtaskstate_26;
    VlMTaskVertex __Vm_mtaskstate_51;
    VlMTaskVertex __Vm_mtaskstate_28;
    VlMTaskVertex __Vm_mtaskstate_31;
    VlMTaskVertex __Vm_mtaskstate_39;
    VlMTaskVertex __Vm_mtaskstate_47;
    VlMTaskVertex __Vm_mtaskstate_52;
    VlMTaskVertex __Vm_mtaskstate_32;
    VlMTaskVertex __Vm_mtaskstate_40;
    VlMTaskVertex __Vm_mtaskstate_48;
    VlMTaskVertex __Vm_mtaskstate_53;
    VlMTaskVertex __Vm_mtaskstate_33;
    VlMTaskVertex __Vm_mtaskstate_41;
    VlMTaskVertex __Vm_mtaskstate_49;
    VlMTaskVertex __Vm_mtaskstate_34;
    VlMTaskVertex __Vm_mtaskstate_42;
    VlMTaskVertex __Vm_mtaskstate_50;
    VlMTaskVertex __Vm_mtaskstate_35;
    VlMTaskVertex __Vm_mtaskstate_43;
    VlMTaskVertex __Vm_mtaskstate_36;
    VlMTaskVertex __Vm_mtaskstate_44;
    VlMTaskVertex __Vm_mtaskstate_37;
    VlMTaskVertex __Vm_mtaskstate_45;
    VlMTaskVertex __Vm_mtaskstate_final__nba;

    // INTERNAL VARIABLES
    Vregister_tree_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vregister_tree_tb___024root(Vregister_tree_tb__Syms* symsp, const char* v__name);
    ~Vregister_tree_tb___024root();
    VL_UNCOPYABLE(Vregister_tree_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
