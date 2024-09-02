// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vregister_tree_tb.h for the primary calling header

#include "Vregister_tree_tb__pch.h"
#include "Vregister_tree_tb___024root.h"

VL_ATTR_COLD void Vregister_tree_tb___024root___eval_initial__TOP(Vregister_tree_tb___024root* vlSelf);
VlCoroutine Vregister_tree_tb___024root___eval_initial__TOP__Vtiming__0(Vregister_tree_tb___024root* vlSelf);
VlCoroutine Vregister_tree_tb___024root___eval_initial__TOP__Vtiming__1(Vregister_tree_tb___024root* vlSelf);

void Vregister_tree_tb___024root___eval_initial(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___eval_initial\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vregister_tree_tb___024root___eval_initial__TOP(vlSelf);
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vregister_tree_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vregister_tree_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__register_tree_tb__DOT__clk__0 
        = vlSelfRef.register_tree_tb__DOT__clk;
}

VL_INLINE_OPT VlCoroutine Vregister_tree_tb___024root___eval_initial__TOP__Vtiming__1(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(5ULL, 
                                             nullptr, 
                                             "register_tree_tb.sv", 
                                             21);
        vlSelfRef.__VdlyVal__register_tree_tb__DOT__clk__v0 
            = (1U & (~ (IData)(vlSelfRef.register_tree_tb__DOT__clk)));
        vlSelfRef.__VdlySet__register_tree_tb__DOT__clk__v0 = 1U;
    }
}

void Vregister_tree_tb___024root___eval_act(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___eval_act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__0(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__register_tree_tb__DOT__dut__DOT__level_indicator 
        = vlSelfRef.register_tree_tb__DOT__dut__DOT__level_indicator;
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__1(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(vlSelfRef.register_tree_tb__DOT__replace)) {
        VL_WRITEF_NX("Top item is %0#, new item is %0#\n",0,
                     32,vlSelfRef.register_tree_tb__DOT__top_item,
                     32,vlSelfRef.register_tree_tb__DOT__new_item);
    }
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__2(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v0 = 0U;
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__3(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__3\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v1 = 0U;
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__4(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__4\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v2 = 0U;
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__5(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__5\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v3 = 0U;
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__6(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__6\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v4 = 0U;
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__7(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__7\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v5 = 0U;
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__8(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__8\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v6 = 0U;
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__9(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__9\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v7 = 0U;
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__10(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__10\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v8 = 0U;
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__11(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__11\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v9 = 0U;
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__12(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__12\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v10 = 0U;
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__13(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__13\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v11 = 0U;
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__14(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__14\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v12 = 0U;
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__15(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__15\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v13 = 0U;
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__16(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__16\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v14 = 0U;
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__17(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__17\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v15 = 0U;
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__18(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__18\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v16 = 0U;
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__19(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__19\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v17 = 0U;
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__20(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__20\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v18 = 0U;
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__21(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__21\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v19 = 0U;
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__22(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__22\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v20 = 0U;
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__23(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__23\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v21 = 0U;
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__24(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__24\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__register_tree_tb__DOT__clk__v0) {
        vlSelfRef.__VdlySet__register_tree_tb__DOT__clk__v0 = 0U;
        vlSelfRef.register_tree_tb__DOT__clk = vlSelfRef.__VdlyVal__register_tree_tb__DOT__clk__v0;
    }
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__26(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__26\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ (IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__level_indicator)))) {
        vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v0 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent
            [0U];
        vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v0 = 1U;
        vlSelfRef.register_tree_tb__DOT__dut__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 7U;
        vlSelfRef.register_tree_tb__DOT__dut__DOT__unnamedblk2__DOT__k = 4U;
        vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v1 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child
            [0U];
        vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v1 = 1U;
        vlSelfRef.__Vdly__register_tree_tb__DOT__dut__DOT__level_indicator = 1U;
        vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v2 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child
            [0U];
        vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v2 = 1U;
        if (vlSelfRef.register_tree_tb__DOT__replace) {
            vlSelfRef.register_tree_tb__DOT__top_item 
                = vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                [0U];
            vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v3 
                = vlSelfRef.register_tree_tb__DOT__new_item;
            vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v3 = 1U;
        }
        vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_hfb5ebc9c__0 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent
            [3U];
        vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v4 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_hfb5ebc9c__0;
        vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v4 = 1U;
        vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_h07d53320__0 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child
            [3U];
        vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v5 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_h07d53320__0;
        vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v5 = 1U;
        vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_h07d501a4__0 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child
            [3U];
        vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v6 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_h07d501a4__0;
        vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v6 = 1U;
        vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_hfb5ebc9c__0 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent
            [4U];
        vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v7 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_hfb5ebc9c__0;
        vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v7 = 1U;
        vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_h07d53320__0 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child
            [4U];
        vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v8 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_h07d53320__0;
        vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v8 = 1U;
        vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_h07d501a4__0 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child
            [4U];
        vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v9 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_h07d501a4__0;
        vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v9 = 1U;
        vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_hfb5ebc9c__0 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent
            [5U];
        vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v10 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_hfb5ebc9c__0;
        vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v10 = 1U;
        vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_h07d53320__0 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child
            [5U];
        vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v11 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_h07d53320__0;
        vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v11 = 1U;
        vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_h07d501a4__0 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child
            [5U];
        vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v12 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_h07d501a4__0;
        vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v12 = 1U;
        vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_hfb5ebc9c__0 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent
            [6U];
        vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v13 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_hfb5ebc9c__0;
        vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v13 = 1U;
        vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_h07d53320__0 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child
            [6U];
        vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v14 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_h07d53320__0;
        vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v14 = 1U;
        vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_h07d501a4__0 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child
            [6U];
        vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v15 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_h07d501a4__0;
        vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v15 = 1U;
    }
    if (vlSelfRef.register_tree_tb__DOT__dut__DOT__level_indicator) {
        vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_ha43e4694__0 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent
            [1U];
        vlSelfRef.register_tree_tb__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__n = 3U;
        vlSelfRef.register_tree_tb__DOT__dut__DOT__unnamedblk4__DOT__m = 3U;
        vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v16 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_ha43e4694__0;
        vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v16 = 1U;
        vlSelfRef.__Vdly__register_tree_tb__DOT__dut__DOT__level_indicator = 0U;
        vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_he77e3845__0 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child
            [1U];
        vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v17 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_he77e3845__0;
        vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v17 = 1U;
        vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_he77e065b__0 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child
            [1U];
        vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v18 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_he77e065b__0;
        vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v18 = 1U;
        vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_ha43e4694__0 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent
            [2U];
        vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v19 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_ha43e4694__0;
        vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v19 = 1U;
        vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_he77e3845__0 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child
            [2U];
        vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v20 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_he77e3845__0;
        vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v20 = 1U;
        vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_he77e065b__0 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child
            [2U];
        vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v21 
            = vlSelfRef.register_tree_tb__DOT__dut__DOT____Vlvbound_he77e065b__0;
        vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v21 = 1U;
    }
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__28(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__28\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.register_tree_tb__DOT__dut__DOT__level_indicator 
        = vlSelfRef.__Vdly__register_tree_tb__DOT__dut__DOT__level_indicator;
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__29(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__29\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v0) {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[0U] 
            = vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v0;
    }
    if (vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v1) {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[1U] 
            = vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v1;
    }
    if (vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v2) {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[2U] 
            = vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v2;
    }
    if (vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v3) {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[0U] 
            = vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v3;
    }
    if (vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v4) {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[3U] 
            = vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v4;
    }
    if (vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v5) {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[7U] 
            = vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v5;
    }
    if (vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v6) {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[8U] 
            = vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v6;
    }
    if (vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v7) {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[4U] 
            = vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v7;
    }
    if (vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v8) {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[9U] 
            = vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v8;
    }
    if (vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v9) {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[0xaU] 
            = vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v9;
    }
    if (vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v10) {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[5U] 
            = vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v10;
    }
    if (vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v11) {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[0xbU] 
            = vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v11;
    }
    if (vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v12) {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[0xcU] 
            = vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v12;
    }
    if (vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v13) {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[6U] 
            = vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v13;
    }
    if (vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v14) {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[0xdU] 
            = vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v14;
    }
    if (vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v15) {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[0xeU] 
            = vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v15;
    }
    if (vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v16) {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[1U] 
            = vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v16;
    }
    if (vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v17) {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[3U] 
            = vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v17;
    }
    if (vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v18) {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[4U] 
            = vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v18;
    }
    if (vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v19) {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[2U] 
            = vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v19;
    }
    if (vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v20) {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[5U] 
            = vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v20;
    }
    if (vlSelfRef.__VdlySet__register_tree_tb__DOT__dut__DOT__tree__v21) {
        vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[6U] 
            = vlSelfRef.__VdlyVal__register_tree_tb__DOT__dut__DOT__tree__v21;
    }
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__30(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__30\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__left_greater_than_right 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [1U] > vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [2U]);
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__31(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__31\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__parent_less_than_left 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [0U] < vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [1U]);
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__32(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__32\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__parent_less_than_right 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [0U] < vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [2U]);
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__33(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__33\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__left_greater_than_right 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [3U] > vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [4U]);
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__34(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__34\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__parent_less_than_left 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [1U] < vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [3U]);
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__35(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__35\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__parent_less_than_right 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [1U] < vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [4U]);
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__36(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__36\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__left_greater_than_right 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [5U] > vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [6U]);
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__37(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__37\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__parent_less_than_left 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [2U] < vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [5U]);
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__38(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__38\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__parent_less_than_right 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [2U] < vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [6U]);
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__39(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__39\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__left_greater_than_right 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [7U] > vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [8U]);
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__40(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__40\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__parent_less_than_left 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [3U] < vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [7U]);
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__41(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__41\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__parent_less_than_right 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [3U] < vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [8U]);
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__42(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__42\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__left_greater_than_right 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [9U] > vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [0xaU]);
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__43(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__43\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__parent_less_than_left 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [4U] < vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [9U]);
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__44(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__44\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__parent_less_than_right 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [4U] < vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [0xaU]);
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__45(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__45\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__left_greater_than_right 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [0xbU] > vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [0xcU]);
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__46(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__46\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__parent_less_than_left 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [5U] < vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [0xbU]);
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__47(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__47\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__parent_less_than_right 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [5U] < vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [0xcU]);
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__48(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__48\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__left_greater_than_right 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [0xdU] > vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [0xeU]);
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__49(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__49\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__parent_less_than_left 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [6U] < vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [0xdU]);
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__50(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__50\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__parent_less_than_right 
        = (vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [6U] < vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
           [0xeU]);
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__51(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__51\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[0U] 
        = ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__left_greater_than_right)
            ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [1U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [0U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                         ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                        [2U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                        [0U]));
    vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[1U] 
        = ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__left_greater_than_right)
            ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [3U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [1U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                         ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                        [4U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                        [1U]));
    vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[2U] 
        = ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__left_greater_than_right)
            ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [5U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [2U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                         ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                        [6U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                        [2U]));
    vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[3U] 
        = ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__left_greater_than_right)
            ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [7U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [3U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                         ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                        [8U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                        [3U]));
    vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[4U] 
        = ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__left_greater_than_right)
            ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [9U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [4U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                         ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                        [0xaU] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                        [4U]));
    vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[5U] 
        = ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__left_greater_than_right)
            ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [0xbU] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [5U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                         ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                        [0xcU] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                        [5U]));
    vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[6U] 
        = ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__left_greater_than_right)
            ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [0xdU] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [6U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                         ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                        [0xeU] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                        [6U]));
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__52(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__52\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[0U] 
        = ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__left_greater_than_right)
            ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [0U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [1U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                         ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                        [1U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                        [1U]));
    vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[1U] 
        = ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__left_greater_than_right)
            ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [1U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [3U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                         ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                        [3U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                        [3U]));
    vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[2U] 
        = ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__left_greater_than_right)
            ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [2U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [5U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                         ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                        [5U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                        [5U]));
    vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[3U] 
        = ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__left_greater_than_right)
            ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [3U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [7U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                         ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                        [7U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                        [7U]));
    vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[4U] 
        = ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__left_greater_than_right)
            ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [4U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [9U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                         ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                        [9U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                        [9U]));
    vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[5U] 
        = ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__left_greater_than_right)
            ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [5U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [0xbU]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                           ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                          [0xbU] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                          [0xbU]));
    vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[6U] 
        = ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__left_greater_than_right)
            ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [6U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [0xdU]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                           ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                          [0xdU] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                          [0xdU]));
}

VL_INLINE_OPT void Vregister_tree_tb___024root___nba_sequent__TOP__53(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___nba_sequent__TOP__53\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[0U] 
        = ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__left_greater_than_right)
            ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [2U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [2U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                         ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                        [0U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                        [2U]));
    vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[1U] 
        = ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__left_greater_than_right)
            ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [4U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [4U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                         ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                        [1U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                        [4U]));
    vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[2U] 
        = ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__left_greater_than_right)
            ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [6U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [6U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                         ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                        [2U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                        [6U]));
    vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[3U] 
        = ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__left_greater_than_right)
            ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [8U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [8U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                         ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                        [3U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                        [8U]));
    vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[4U] 
        = ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__left_greater_than_right)
            ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [0xaU] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [0xaU]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                           ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                          [4U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                          [0xaU]));
    vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[5U] 
        = ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__left_greater_than_right)
            ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [0xcU] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [0xcU]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                           ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                          [5U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                          [0xcU]));
    vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[6U] 
        = ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__left_greater_than_right)
            ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [0xeU] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
               [0xeU]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                           ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                          [6U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                          [0xeU]));
}

void Vregister_tree_tb___024root___timing_resume(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___timing_resume\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_hf71ee19c__0.resume(
                                                   "@(posedge register_tree_tb.clk)");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vregister_tree_tb___024root___timing_commit(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___timing_commit\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (1ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_hf71ee19c__0.commit(
                                                   "@(posedge register_tree_tb.clk)");
    }
}

void Vregister_tree_tb___024root___eval_triggers__act(Vregister_tree_tb___024root* vlSelf);

bool Vregister_tree_tb___024root___eval_phase__act(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vregister_tree_tb___024root___eval_triggers__act(vlSelf);
    Vregister_tree_tb___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vregister_tree_tb___024root___timing_resume(vlSelf);
        Vregister_tree_tb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void Vregister_tree_tb___024root___eval_nba(Vregister_tree_tb___024root* vlSelf);

bool Vregister_tree_tb___024root___eval_phase__nba(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vregister_tree_tb___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vregister_tree_tb___024root___dump_triggers__nba(Vregister_tree_tb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vregister_tree_tb___024root___dump_triggers__act(Vregister_tree_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vregister_tree_tb___024root___eval(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___eval\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vregister_tree_tb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("register_tree_tb.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vregister_tree_tb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("register_tree_tb.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vregister_tree_tb___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vregister_tree_tb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vregister_tree_tb___024root___eval_debug_assertions(Vregister_tree_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
