// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vregister_tree_tb.h for the primary calling header

#include "Vregister_tree_tb__pch.h"
#include "Vregister_tree_tb___024root.h"

VL_ATTR_COLD void Vregister_tree_tb___024root___eval_static__TOP(Vregister_tree_tb___024root* vlSelf);

VL_ATTR_COLD void Vregister_tree_tb___024root___eval_static(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___eval_static\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vregister_tree_tb___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void Vregister_tree_tb___024root___eval_static__TOP(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___eval_static__TOP\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.register_tree_tb__DOT__dut__DOT__level_indicator = 0U;
}

VL_ATTR_COLD void Vregister_tree_tb___024root___eval_initial__TOP(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___eval_initial__TOP\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[0U] = 0xaU;
    vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[1U] = 0x14U;
    vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[2U] = 0x1eU;
    vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[3U] = 0x28U;
    vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[4U] = 0x32U;
    vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[5U] = 0x3cU;
    vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[6U] = 0x46U;
    vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[7U] = 0x50U;
    vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[8U] = 0x5aU;
    vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[9U] = 0x64U;
    vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[0xaU] = 0x6eU;
    vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[0xbU] = 0x78U;
    vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[0xcU] = 0x82U;
    vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[0xdU] = 0x8cU;
    vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[0xeU] = 0x96U;
    vlSelfRef.register_tree_tb__DOT__dut__DOT__unnamedblk1__DOT__j = 0xfU;
}

VL_ATTR_COLD void Vregister_tree_tb___024root___eval_final(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___eval_final\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vregister_tree_tb___024root___dump_triggers__stl(Vregister_tree_tb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vregister_tree_tb___024root___eval_phase__stl(Vregister_tree_tb___024root* vlSelf);

VL_ATTR_COLD void Vregister_tree_tb___024root___eval_settle(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___eval_settle\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vregister_tree_tb___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("register_tree_tb.sv", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vregister_tree_tb___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vregister_tree_tb___024root___dump_triggers__stl(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___dump_triggers__stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vregister_tree_tb___024root___stl_sequent__TOP__0(Vregister_tree_tb___024root* vlSelf);

VL_ATTR_COLD void Vregister_tree_tb___024root___eval_stl(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___eval_stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vregister_tree_tb___024root___stl_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[7U] = 1U;
        vlSelfRef.__Vm_traceActivity[6U] = 1U;
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
        vlSelfRef.__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Vregister_tree_tb___024root___stl_sequent__TOP__0(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___stl_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__left_greater_than_right 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [1U] > vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [2U]);
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__parent_less_than_left 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [0U] < vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [1U]);
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__parent_less_than_right 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [0U] < vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [2U]);
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__left_greater_than_right 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [3U] > vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [4U]);
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__parent_less_than_left 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [1U] < vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [3U]);
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__parent_less_than_right 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [1U] < vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [4U]);
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__left_greater_than_right 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [5U] > vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [6U]);
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__parent_less_than_left 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [2U] < vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [5U]);
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__parent_less_than_right 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [2U] < vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [6U]);
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__left_greater_than_right 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [7U] > vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [8U]);
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__parent_less_than_left 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [3U] < vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [7U]);
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__parent_less_than_right 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [3U] < vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [8U]);
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__left_greater_than_right 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [9U] > vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [0xaU]);
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__parent_less_than_left 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [4U] < vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [9U]);
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__parent_less_than_right 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [4U] < vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [0xaU]);
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__left_greater_than_right 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [0xbU] > vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [0xcU]);
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__parent_less_than_left 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [5U] < vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [0xbU]);
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__parent_less_than_right 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [5U] < vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [0xcU]);
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__left_greater_than_right 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [0xdU] > vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [0xeU]);
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__parent_less_than_left 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [6U] < vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [0xdU]);
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__parent_less_than_right 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [6U] < vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [0xeU]);
    if (vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__left_greater_than_right) {
        if (vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__parent_less_than_left) {
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[0U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [1U];
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[0U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [0U];
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[0U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [2U];
        } else {
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[0U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [0U];
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[0U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [1U];
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[0U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [2U];
        }
    } else if (vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__parent_less_than_right) {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[0U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [2U];
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[0U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [1U];
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[0U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [0U];
    } else {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[0U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [0U];
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[0U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [1U];
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[0U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [2U];
    }
    if (vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__left_greater_than_right) {
        if (vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__parent_less_than_left) {
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[1U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [3U];
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[1U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [1U];
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[1U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [4U];
        } else {
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[1U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [1U];
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[1U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [3U];
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[1U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [4U];
        }
    } else if (vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__parent_less_than_right) {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[1U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [4U];
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[1U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [3U];
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[1U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [1U];
    } else {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[1U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [1U];
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[1U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [3U];
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[1U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [4U];
    }
    if (vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__left_greater_than_right) {
        if (vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__parent_less_than_left) {
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[2U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [5U];
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[2U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [2U];
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[2U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [6U];
        } else {
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[2U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [2U];
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[2U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [5U];
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[2U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [6U];
        }
    } else if (vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__parent_less_than_right) {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[2U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [6U];
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[2U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [5U];
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[2U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [2U];
    } else {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[2U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [2U];
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[2U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [5U];
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[2U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [6U];
    }
    if (vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__left_greater_than_right) {
        if (vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__parent_less_than_left) {
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[3U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [7U];
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[3U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [3U];
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[3U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [8U];
        } else {
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[3U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [3U];
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[3U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [7U];
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[3U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [8U];
        }
    } else if (vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__parent_less_than_right) {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[3U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [8U];
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[3U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [7U];
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[3U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [3U];
    } else {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[3U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [3U];
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[3U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [7U];
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[3U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [8U];
    }
    if (vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__left_greater_than_right) {
        if (vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__parent_less_than_left) {
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[4U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [9U];
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[4U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [4U];
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[4U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [0xaU];
        } else {
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[4U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [4U];
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[4U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [9U];
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[4U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [0xaU];
        }
    } else if (vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__parent_less_than_right) {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[4U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [0xaU];
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[4U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [9U];
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[4U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [4U];
    } else {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[4U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [4U];
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[4U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [9U];
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[4U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [0xaU];
    }
    if (vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__left_greater_than_right) {
        if (vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__parent_less_than_left) {
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[5U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [0xbU];
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[5U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [5U];
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[5U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [0xcU];
        } else {
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[5U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [5U];
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[5U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [0xbU];
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[5U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [0xcU];
        }
    } else if (vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__parent_less_than_right) {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[5U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [0xcU];
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[5U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [0xbU];
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[5U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [5U];
    } else {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[5U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [5U];
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[5U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [0xbU];
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[5U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [0xcU];
    }
    if (vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__left_greater_than_right) {
        if (vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__parent_less_than_left) {
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[6U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [0xdU];
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[6U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [6U];
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[6U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [0xeU];
        } else {
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[6U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [6U];
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[6U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [0xdU];
            vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[6U] 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [0xeU];
        }
    } else if (vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__parent_less_than_right) {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[6U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [0xeU];
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[6U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [0xdU];
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[6U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [6U];
    } else {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[6U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [6U];
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[6U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [0xdU];
        vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[6U] 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
            [0xeU];
    }
}

VL_ATTR_COLD void Vregister_tree_tb___024root___eval_triggers__stl(Vregister_tree_tb___024root* vlSelf);

VL_ATTR_COLD bool Vregister_tree_tb___024root___eval_phase__stl(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___eval_phase__stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vregister_tree_tb___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vregister_tree_tb___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vregister_tree_tb___024root___dump_triggers__act(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___dump_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge register_tree_tb.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vregister_tree_tb___024root___dump_triggers__nba(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___dump_triggers__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge register_tree_tb.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vregister_tree_tb___024root___ctor_var_reset(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___ctor_var_reset\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->register_tree_tb__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->register_tree_tb__DOT__replace = VL_RAND_RESET_I(1);
    vlSelf->register_tree_tb__DOT__new_item = VL_RAND_RESET_I(32);
    vlSelf->register_tree_tb__DOT__top_item = VL_RAND_RESET_I(32);
    vlSelf->register_tree_tb__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->register_tree_tb__DOT__unnamedblk2__DOT__i = 0;
    vlSelf->register_tree_tb__DOT__unnamedblk3__DOT__i = 0;
    vlSelf->register_tree_tb__DOT__unnamedblk4__DOT__i = 0;
    vlSelf->register_tree_tb__DOT__unnamedblk5__DOT__i = 0;
    for (int __Vi0 = 0; __Vi0 < 15; ++__Vi0) {
        vlSelf->register_tree_tb__DOT__dut__DOT__tree[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 7; ++__Vi0) {
        vlSelf->register_tree_tb__DOT__dut__DOT__new_parent[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 7; ++__Vi0) {
        vlSelf->register_tree_tb__DOT__dut__DOT__new_left_child[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 7; ++__Vi0) {
        vlSelf->register_tree_tb__DOT__dut__DOT__new_right_child[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->register_tree_tb__DOT__dut__DOT__level_indicator = VL_RAND_RESET_I(1);
    vlSelf->register_tree_tb__DOT__dut__DOT__unnamedblk1__DOT__j = VL_RAND_RESET_I(32);
    vlSelf->register_tree_tb__DOT__dut__DOT__unnamedblk2__DOT__k = VL_RAND_RESET_I(32);
    vlSelf->register_tree_tb__DOT__dut__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = VL_RAND_RESET_I(32);
    vlSelf->register_tree_tb__DOT__dut__DOT__unnamedblk4__DOT__m = VL_RAND_RESET_I(32);
    vlSelf->register_tree_tb__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__n = VL_RAND_RESET_I(32);
    vlSelf->register_tree_tb__DOT__dut__DOT____Vlvbound_hfb5ebc9c__0 = VL_RAND_RESET_I(32);
    vlSelf->register_tree_tb__DOT__dut__DOT____Vlvbound_h07d53320__0 = VL_RAND_RESET_I(32);
    vlSelf->register_tree_tb__DOT__dut__DOT____Vlvbound_h07d501a4__0 = VL_RAND_RESET_I(32);
    vlSelf->register_tree_tb__DOT__dut__DOT____Vlvbound_ha43e4694__0 = VL_RAND_RESET_I(32);
    vlSelf->register_tree_tb__DOT__dut__DOT____Vlvbound_he77e3845__0 = VL_RAND_RESET_I(32);
    vlSelf->register_tree_tb__DOT__dut__DOT____Vlvbound_he77e065b__0 = VL_RAND_RESET_I(32);
    vlSelf->register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__left_greater_than_right = VL_RAND_RESET_I(1);
    vlSelf->register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__parent_less_than_left = VL_RAND_RESET_I(1);
    vlSelf->register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__parent_less_than_right = VL_RAND_RESET_I(1);
    vlSelf->register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__left_greater_than_right = VL_RAND_RESET_I(1);
    vlSelf->register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__parent_less_than_left = VL_RAND_RESET_I(1);
    vlSelf->register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__parent_less_than_right = VL_RAND_RESET_I(1);
    vlSelf->register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__left_greater_than_right = VL_RAND_RESET_I(1);
    vlSelf->register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__parent_less_than_left = VL_RAND_RESET_I(1);
    vlSelf->register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__parent_less_than_right = VL_RAND_RESET_I(1);
    vlSelf->register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__left_greater_than_right = VL_RAND_RESET_I(1);
    vlSelf->register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__parent_less_than_left = VL_RAND_RESET_I(1);
    vlSelf->register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__parent_less_than_right = VL_RAND_RESET_I(1);
    vlSelf->register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__left_greater_than_right = VL_RAND_RESET_I(1);
    vlSelf->register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__parent_less_than_left = VL_RAND_RESET_I(1);
    vlSelf->register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__parent_less_than_right = VL_RAND_RESET_I(1);
    vlSelf->register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__left_greater_than_right = VL_RAND_RESET_I(1);
    vlSelf->register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__parent_less_than_left = VL_RAND_RESET_I(1);
    vlSelf->register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__parent_less_than_right = VL_RAND_RESET_I(1);
    vlSelf->register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__left_greater_than_right = VL_RAND_RESET_I(1);
    vlSelf->register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__parent_less_than_left = VL_RAND_RESET_I(1);
    vlSelf->register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__parent_less_than_right = VL_RAND_RESET_I(1);
    vlSelf->__VdlyVal__register_tree_tb__DOT__clk__v0 = VL_RAND_RESET_I(1);
    vlSelf->__VdlySet__register_tree_tb__DOT__clk__v0 = 0;
    vlSelf->__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v0 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v1 = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__register_tree_tb__DOT__dut__DOT__level_indicator = VL_RAND_RESET_I(1);
    vlSelf->__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v2 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v3 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v4 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v5 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v6 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v7 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v8 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v9 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v10 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v11 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v12 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v13 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v14 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v15 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v16 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v17 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v18 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v19 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v20 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v21 = VL_RAND_RESET_I(32);
    vlSelf->__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v0 = 0;
    vlSelf->__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v1 = 0;
    vlSelf->__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v2 = 0;
    vlSelf->__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v3 = 0;
    vlSelf->__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v4 = 0;
    vlSelf->__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v5 = 0;
    vlSelf->__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v6 = 0;
    vlSelf->__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v7 = 0;
    vlSelf->__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v8 = 0;
    vlSelf->__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v9 = 0;
    vlSelf->__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v10 = 0;
    vlSelf->__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v11 = 0;
    vlSelf->__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v12 = 0;
    vlSelf->__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v13 = 0;
    vlSelf->__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v14 = 0;
    vlSelf->__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v15 = 0;
    vlSelf->__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v16 = 0;
    vlSelf->__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v17 = 0;
    vlSelf->__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v18 = 0;
    vlSelf->__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v19 = 0;
    vlSelf->__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v20 = 0;
    vlSelf->__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v21 = 0;
    vlSelf->__Vtrigprevexpr___TOP__register_tree_tb__DOT__clk__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
