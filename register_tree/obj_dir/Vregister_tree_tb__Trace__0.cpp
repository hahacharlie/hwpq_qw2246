// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vregister_tree_tb__Syms.h"


void Vregister_tree_tb___024root__trace_chg_0_sub_0(Vregister_tree_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vregister_tree_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root__trace_chg_0\n"); );
    // Init
    Vregister_tree_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vregister_tree_tb___024root*>(voidSelf);
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vregister_tree_tb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vregister_tree_tb___024root__trace_chg_0_sub_0(Vregister_tree_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root__trace_chg_0_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U] 
                     | vlSelfRef.__Vm_traceActivity
                     [2U]))) {
        bufp->chgBit(oldp+0,(vlSelfRef.register_tree_tb__DOT__replace));
        bufp->chgIData(oldp+1,(vlSelfRef.register_tree_tb__DOT__new_item),32);
        bufp->chgIData(oldp+2,(vlSelfRef.register_tree_tb__DOT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+3,(vlSelfRef.register_tree_tb__DOT__unnamedblk2__DOT__i),32);
        bufp->chgIData(oldp+4,(vlSelfRef.register_tree_tb__DOT__unnamedblk3__DOT__i),32);
        bufp->chgIData(oldp+5,(vlSelfRef.register_tree_tb__DOT__unnamedblk4__DOT__i),32);
        bufp->chgIData(oldp+6,(vlSelfRef.register_tree_tb__DOT__unnamedblk5__DOT__i),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U] 
                     | vlSelfRef.__Vm_traceActivity
                     [4U]))) {
        bufp->chgIData(oldp+7,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[0]),32);
        bufp->chgIData(oldp+8,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[1]),32);
        bufp->chgIData(oldp+9,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[2]),32);
        bufp->chgIData(oldp+10,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[3]),32);
        bufp->chgIData(oldp+11,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[4]),32);
        bufp->chgIData(oldp+12,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[5]),32);
        bufp->chgIData(oldp+13,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[6]),32);
        bufp->chgIData(oldp+14,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[7]),32);
        bufp->chgIData(oldp+15,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[8]),32);
        bufp->chgIData(oldp+16,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[9]),32);
        bufp->chgIData(oldp+17,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[10]),32);
        bufp->chgIData(oldp+18,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[11]),32);
        bufp->chgIData(oldp+19,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[12]),32);
        bufp->chgIData(oldp+20,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[13]),32);
        bufp->chgIData(oldp+21,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[14]),32);
    }
}

void Vregister_tree_tb___024root__trace_chg_1_sub_0(Vregister_tree_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vregister_tree_tb___024root__trace_chg_1(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root__trace_chg_1\n"); );
    // Init
    Vregister_tree_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vregister_tree_tb___024root*>(voidSelf);
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vregister_tree_tb___024root__trace_chg_1_sub_0((&vlSymsp->TOP), bufp);
}

void Vregister_tree_tb___024root__trace_chg_1_sub_0(Vregister_tree_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root__trace_chg_1_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 23);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U] 
                     | vlSelfRef.__Vm_traceActivity
                     [4U]))) {
        bufp->chgIData(oldp+0,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                               [0U]),32);
        bufp->chgIData(oldp+1,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                               [1U]),32);
        bufp->chgIData(oldp+2,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                               [2U]),32);
        bufp->chgIData(oldp+3,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                               [3U]),32);
        bufp->chgIData(oldp+4,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                               [4U]),32);
        bufp->chgIData(oldp+5,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                               [5U]),32);
        bufp->chgIData(oldp+6,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                               [6U]),32);
        bufp->chgIData(oldp+7,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                               [7U]),32);
        bufp->chgIData(oldp+8,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                               [8U]),32);
        bufp->chgIData(oldp+9,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                               [9U]),32);
        bufp->chgIData(oldp+10,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                [0xaU]),32);
        bufp->chgIData(oldp+11,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                [0xbU]),32);
        bufp->chgIData(oldp+12,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                [0xcU]),32);
        bufp->chgIData(oldp+13,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                [0xdU]),32);
    }
}

void Vregister_tree_tb___024root__trace_chg_2_sub_0(Vregister_tree_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vregister_tree_tb___024root__trace_chg_2(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root__trace_chg_2\n"); );
    // Init
    Vregister_tree_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vregister_tree_tb___024root*>(voidSelf);
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vregister_tree_tb___024root__trace_chg_2_sub_0((&vlSymsp->TOP), bufp);
}

void Vregister_tree_tb___024root__trace_chg_2_sub_0(Vregister_tree_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root__trace_chg_2_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 37);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U] 
                     | vlSelfRef.__Vm_traceActivity
                     [4U]))) {
        bufp->chgIData(oldp+0,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                               [0xeU]),32);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[3U])) {
        bufp->chgIData(oldp+1,(vlSelfRef.register_tree_tb__DOT__top_item),32);
        bufp->chgIData(oldp+2,(vlSelfRef.register_tree_tb__DOT__dut__DOT__unnamedblk2__DOT__k),32);
        bufp->chgIData(oldp+3,(vlSelfRef.register_tree_tb__DOT__dut__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j),32);
        bufp->chgIData(oldp+4,(vlSelfRef.register_tree_tb__DOT__dut__DOT__unnamedblk4__DOT__m),32);
        bufp->chgIData(oldp+5,(vlSelfRef.register_tree_tb__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__n),32);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[5U])) {
        bufp->chgIData(oldp+6,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[0]),32);
        bufp->chgIData(oldp+7,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[1]),32);
        bufp->chgIData(oldp+8,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[2]),32);
        bufp->chgIData(oldp+9,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[3]),32);
        bufp->chgIData(oldp+10,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[4]),32);
        bufp->chgIData(oldp+11,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[5]),32);
        bufp->chgIData(oldp+12,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[6]),32);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[6U])) {
        bufp->chgIData(oldp+13,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[0]),32);
        bufp->chgIData(oldp+14,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[1]),32);
        bufp->chgIData(oldp+15,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[2]),32);
        bufp->chgIData(oldp+16,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[3]),32);
        bufp->chgIData(oldp+17,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[4]),32);
        bufp->chgIData(oldp+18,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[5]),32);
        bufp->chgIData(oldp+19,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[6]),32);
    }
}

void Vregister_tree_tb___024root__trace_chg_3_sub_0(Vregister_tree_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vregister_tree_tb___024root__trace_chg_3(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root__trace_chg_3\n"); );
    // Init
    Vregister_tree_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vregister_tree_tb___024root*>(voidSelf);
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vregister_tree_tb___024root__trace_chg_3_sub_0((&vlSymsp->TOP), bufp);
}

void Vregister_tree_tb___024root__trace_chg_3_sub_0(Vregister_tree_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root__trace_chg_3_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 57);
    // Body
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[7U])) {
        bufp->chgIData(oldp+0,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[0]),32);
        bufp->chgIData(oldp+1,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[1]),32);
        bufp->chgIData(oldp+2,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[2]),32);
        bufp->chgIData(oldp+3,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[3]),32);
        bufp->chgIData(oldp+4,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[4]),32);
        bufp->chgIData(oldp+5,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[5]),32);
        bufp->chgIData(oldp+6,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[6]),32);
    }
    bufp->chgBit(oldp+7,(vlSelfRef.register_tree_tb__DOT__clk));
    bufp->chgBit(oldp+8,(vlSelfRef.register_tree_tb__DOT__dut__DOT__level_indicator));
    bufp->chgIData(oldp+9,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                             ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                 ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                [1U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                [0U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                          ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                         [2U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                         [0U]))),32);
    bufp->chgIData(oldp+10,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                              ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                  ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                 [0U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                 [1U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                           ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                          [1U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                          [1U]))),32);
    bufp->chgIData(oldp+11,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                              ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                  ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                 [2U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                 [2U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                           ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                          [0U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                          [2U]))),32);
    bufp->chgBit(oldp+12,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__left_greater_than_right));
    bufp->chgBit(oldp+13,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__parent_less_than_left));
}

void Vregister_tree_tb___024root__trace_chg_4_sub_0(Vregister_tree_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vregister_tree_tb___024root__trace_chg_4(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root__trace_chg_4\n"); );
    // Init
    Vregister_tree_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vregister_tree_tb___024root*>(voidSelf);
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vregister_tree_tb___024root__trace_chg_4_sub_0((&vlSymsp->TOP), bufp);
}

void Vregister_tree_tb___024root__trace_chg_4_sub_0(Vregister_tree_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root__trace_chg_4_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 71);
    // Body
    bufp->chgBit(oldp+0,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__parent_less_than_right));
    bufp->chgIData(oldp+1,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                             ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                 ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                [3U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                [1U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                          ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                         [4U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                         [1U]))),32);
    bufp->chgIData(oldp+2,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                             ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                 ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                [1U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                [3U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                          ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                         [3U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                         [3U]))),32);
    bufp->chgIData(oldp+3,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                             ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                 ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                [4U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                [4U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                          ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                         [1U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                         [4U]))),32);
    bufp->chgBit(oldp+4,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__left_greater_than_right));
    bufp->chgBit(oldp+5,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__parent_less_than_left));
    bufp->chgBit(oldp+6,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__parent_less_than_right));
    bufp->chgIData(oldp+7,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                             ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                 ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                [5U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                [2U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                          ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                         [6U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                         [2U]))),32);
    bufp->chgIData(oldp+8,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                             ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                 ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                [2U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                [5U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                          ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                         [5U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                         [5U]))),32);
    bufp->chgIData(oldp+9,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                             ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                 ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                [6U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                [6U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                          ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                         [2U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                         [6U]))),32);
    bufp->chgBit(oldp+10,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__left_greater_than_right));
    bufp->chgBit(oldp+11,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__parent_less_than_left));
    bufp->chgBit(oldp+12,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__parent_less_than_right));
    bufp->chgIData(oldp+13,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                              ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                  ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                 [7U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                 [3U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                           ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                          [8U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                          [3U]))),32);
}

void Vregister_tree_tb___024root__trace_chg_5_sub_0(Vregister_tree_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vregister_tree_tb___024root__trace_chg_5(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root__trace_chg_5\n"); );
    // Init
    Vregister_tree_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vregister_tree_tb___024root*>(voidSelf);
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vregister_tree_tb___024root__trace_chg_5_sub_0((&vlSymsp->TOP), bufp);
}

void Vregister_tree_tb___024root__trace_chg_5_sub_0(Vregister_tree_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root__trace_chg_5_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 85);
    // Body
    bufp->chgIData(oldp+0,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                             ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                 ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                [3U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                [7U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                          ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                         [7U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                         [7U]))),32);
    bufp->chgIData(oldp+1,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                             ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                 ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                [8U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                [8U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                          ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                         [3U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                         [8U]))),32);
    bufp->chgBit(oldp+2,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__left_greater_than_right));
    bufp->chgBit(oldp+3,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__parent_less_than_left));
    bufp->chgBit(oldp+4,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__parent_less_than_right));
    bufp->chgIData(oldp+5,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                             ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                 ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                [9U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                [4U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                          ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                         [0xaU] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                         [4U]))),32);
    bufp->chgIData(oldp+6,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                             ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                 ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                [4U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                [9U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                          ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                         [9U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                         [9U]))),32);
    bufp->chgIData(oldp+7,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                             ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                 ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                [0xaU] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                [0xaU]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                            ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [4U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [0xaU]))),32);
    bufp->chgBit(oldp+8,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__left_greater_than_right));
    bufp->chgBit(oldp+9,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__parent_less_than_left));
    bufp->chgBit(oldp+10,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__parent_less_than_right));
    bufp->chgIData(oldp+11,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                              ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                  ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                 [0xbU] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                 [5U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                           ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                          [0xcU] : 
                                          vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                          [5U]))),32);
    bufp->chgIData(oldp+12,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                              ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                  ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                 [5U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                 [0xbU]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                             ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                            [0xbU] : 
                                            vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                            [0xbU]))),32);
    bufp->chgIData(oldp+13,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                              ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                  ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                 [0xcU] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                 [0xcU]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                             ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                            [5U] : 
                                            vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                            [0xcU]))),32);
}

void Vregister_tree_tb___024root__trace_chg_6_sub_0(Vregister_tree_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vregister_tree_tb___024root__trace_chg_6(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root__trace_chg_6\n"); );
    // Init
    Vregister_tree_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vregister_tree_tb___024root*>(voidSelf);
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vregister_tree_tb___024root__trace_chg_6_sub_0((&vlSymsp->TOP), bufp);
}

void Vregister_tree_tb___024root__trace_chg_6_sub_0(Vregister_tree_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root__trace_chg_6_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 99);
    // Body
    bufp->chgBit(oldp+0,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__left_greater_than_right));
    bufp->chgBit(oldp+1,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__parent_less_than_left));
    bufp->chgBit(oldp+2,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__parent_less_than_right));
    bufp->chgIData(oldp+3,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                             ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                 ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                [0xdU] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                [6U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                          ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                         [0xeU] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                         [6U]))),32);
    bufp->chgIData(oldp+4,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                             ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                 ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                [6U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                [0xdU]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                            ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [0xdU] : 
                                           vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [0xdU]))),32);
    bufp->chgIData(oldp+5,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                             ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                 ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                [0xeU] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                [0xeU]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                            ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [6U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [0xeU]))),32);
    bufp->chgBit(oldp+6,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__left_greater_than_right));
    bufp->chgBit(oldp+7,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__parent_less_than_left));
    bufp->chgBit(oldp+8,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__parent_less_than_right));
    bufp->chgIData(oldp+9,(vlSelfRef.register_tree_tb__DOT__dut__DOT__unnamedblk1__DOT__j),32);
}

void Vregister_tree_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root__trace_cleanup\n"); );
    // Init
    Vregister_tree_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vregister_tree_tb___024root*>(voidSelf);
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[7U] = 0U;
}
