// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vregister_tree_tb__Syms.h"


VL_ATTR_COLD void Vregister_tree_tb___024root__trace_init_sub__TOP__0(Vregister_tree_tb___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root__trace_init_sub__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("register_tree_tb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+109,0,"TREE_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+110,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+64,3,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"replace",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"new_item",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+38,2,"top_item",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+109,0,"TREE_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+110,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+64,3,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"replace",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"new_item",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+38,2,"top_item",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+111,0,"NUM_NODES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("tree", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 15; ++i) {
        tracep->declBus(c+8+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("new_parent", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+43+i*1,2,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("new_left_child", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+50+i*1,2,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("new_right_child", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+57+i*1,3,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBit(c+65,3,"level_indicator",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("comparator_units[0]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("comparator_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+110,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+23,1,"parent",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+24,1,"left_child",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+25,1,"right_child",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+66,3,"new_parent",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+67,3,"new_left_child",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+68,3,"new_right_child",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+69,3,"left_greater_than_right",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+70,3,"parent_less_than_left",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+71,4,"parent_less_than_right",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("comparator_units[1]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("comparator_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+110,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+24,1,"parent",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+26,1,"left_child",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+27,1,"right_child",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+72,4,"new_parent",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+73,4,"new_left_child",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+74,4,"new_right_child",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+75,4,"left_greater_than_right",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+76,4,"parent_less_than_left",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+77,4,"parent_less_than_right",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("comparator_units[2]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("comparator_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+110,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+25,1,"parent",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+28,1,"left_child",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+29,1,"right_child",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+78,4,"new_parent",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+79,4,"new_left_child",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+80,4,"new_right_child",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+81,4,"left_greater_than_right",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+82,4,"parent_less_than_left",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+83,4,"parent_less_than_right",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("comparator_units[3]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("comparator_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+110,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+26,1,"parent",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+30,1,"left_child",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+31,1,"right_child",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+84,4,"new_parent",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+85,5,"new_left_child",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+86,5,"new_right_child",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+87,5,"left_greater_than_right",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+88,5,"parent_less_than_left",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,5,"parent_less_than_right",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("comparator_units[4]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("comparator_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+110,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+27,1,"parent",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+32,1,"left_child",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+33,1,"right_child",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+90,5,"new_parent",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+91,5,"new_left_child",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+92,5,"new_right_child",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+93,5,"left_greater_than_right",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+94,5,"parent_less_than_left",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+95,5,"parent_less_than_right",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("comparator_units[5]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("comparator_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+110,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+28,1,"parent",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+34,1,"left_child",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+35,1,"right_child",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+96,5,"new_parent",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+97,5,"new_left_child",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+98,5,"new_right_child",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+99,6,"left_greater_than_right",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+100,6,"parent_less_than_left",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+101,6,"parent_less_than_right",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("comparator_units[6]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("comparator_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+110,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+29,1,"parent",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+36,1,"left_child",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+37,2,"right_child",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+102,6,"new_parent",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+103,6,"new_left_child",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+104,6,"new_right_child",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+105,6,"left_greater_than_right",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+106,6,"parent_less_than_left",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+107,6,"parent_less_than_right",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+108,6,"j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+39,2,"k",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->pushPrefix("unnamedblk3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+40,2,"j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk4", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+41,2,"m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->pushPrefix("unnamedblk5", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+42,2,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+3,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+4,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+5,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk4", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+6,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk5", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+7,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vregister_tree_tb___024root__trace_init_top(Vregister_tree_tb___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root__trace_init_top\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vregister_tree_tb___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vregister_tree_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vregister_tree_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vregister_tree_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vregister_tree_tb___024root__trace_full_1(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vregister_tree_tb___024root__trace_chg_1(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vregister_tree_tb___024root__trace_full_2(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vregister_tree_tb___024root__trace_chg_2(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vregister_tree_tb___024root__trace_full_3(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vregister_tree_tb___024root__trace_chg_3(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vregister_tree_tb___024root__trace_full_4(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vregister_tree_tb___024root__trace_chg_4(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vregister_tree_tb___024root__trace_full_5(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vregister_tree_tb___024root__trace_chg_5(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vregister_tree_tb___024root__trace_full_6(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vregister_tree_tb___024root__trace_chg_6(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vregister_tree_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vregister_tree_tb___024root__trace_register(Vregister_tree_tb___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root__trace_register\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vregister_tree_tb___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vregister_tree_tb___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vregister_tree_tb___024root__trace_chg_0, 0U, vlSelf);
    tracep->addFullCb(&Vregister_tree_tb___024root__trace_full_1, 1U, vlSelf);
    tracep->addChgCb(&Vregister_tree_tb___024root__trace_chg_1, 1U, vlSelf);
    tracep->addFullCb(&Vregister_tree_tb___024root__trace_full_2, 2U, vlSelf);
    tracep->addChgCb(&Vregister_tree_tb___024root__trace_chg_2, 2U, vlSelf);
    tracep->addFullCb(&Vregister_tree_tb___024root__trace_full_3, 3U, vlSelf);
    tracep->addChgCb(&Vregister_tree_tb___024root__trace_chg_3, 3U, vlSelf);
    tracep->addFullCb(&Vregister_tree_tb___024root__trace_full_4, 4U, vlSelf);
    tracep->addChgCb(&Vregister_tree_tb___024root__trace_chg_4, 4U, vlSelf);
    tracep->addFullCb(&Vregister_tree_tb___024root__trace_full_5, 5U, vlSelf);
    tracep->addChgCb(&Vregister_tree_tb___024root__trace_chg_5, 5U, vlSelf);
    tracep->addFullCb(&Vregister_tree_tb___024root__trace_full_6, 6U, vlSelf);
    tracep->addChgCb(&Vregister_tree_tb___024root__trace_chg_6, 6U, vlSelf);
    tracep->addCleanupCb(&Vregister_tree_tb___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vregister_tree_tb___024root__trace_const_0_sub_0(Vregister_tree_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vregister_tree_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root__trace_const_0\n"); );
    // Init
    Vregister_tree_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vregister_tree_tb___024root*>(voidSelf);
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vregister_tree_tb___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vregister_tree_tb___024root__trace_const_0_sub_0(Vregister_tree_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root__trace_const_0_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+109,(4U),32);
    bufp->fullIData(oldp+110,(0x20U),32);
    bufp->fullIData(oldp+111,(0xfU),32);
}

VL_ATTR_COLD void Vregister_tree_tb___024root__trace_full_0_sub_0(Vregister_tree_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vregister_tree_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root__trace_full_0\n"); );
    // Init
    Vregister_tree_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vregister_tree_tb___024root*>(voidSelf);
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vregister_tree_tb___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vregister_tree_tb___024root__trace_full_0_sub_0(Vregister_tree_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root__trace_full_0_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelfRef.register_tree_tb__DOT__replace));
    bufp->fullIData(oldp+2,(vlSelfRef.register_tree_tb__DOT__new_item),32);
    bufp->fullIData(oldp+3,(vlSelfRef.register_tree_tb__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+4,(vlSelfRef.register_tree_tb__DOT__unnamedblk2__DOT__i),32);
    bufp->fullIData(oldp+5,(vlSelfRef.register_tree_tb__DOT__unnamedblk3__DOT__i),32);
    bufp->fullIData(oldp+6,(vlSelfRef.register_tree_tb__DOT__unnamedblk4__DOT__i),32);
    bufp->fullIData(oldp+7,(vlSelfRef.register_tree_tb__DOT__unnamedblk5__DOT__i),32);
    bufp->fullIData(oldp+8,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[0]),32);
    bufp->fullIData(oldp+9,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[1]),32);
    bufp->fullIData(oldp+10,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[2]),32);
    bufp->fullIData(oldp+11,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[3]),32);
    bufp->fullIData(oldp+12,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[4]),32);
    bufp->fullIData(oldp+13,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[5]),32);
    bufp->fullIData(oldp+14,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[6]),32);
    bufp->fullIData(oldp+15,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[7]),32);
    bufp->fullIData(oldp+16,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[8]),32);
    bufp->fullIData(oldp+17,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[9]),32);
    bufp->fullIData(oldp+18,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[10]),32);
    bufp->fullIData(oldp+19,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[11]),32);
    bufp->fullIData(oldp+20,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[12]),32);
    bufp->fullIData(oldp+21,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[13]),32);
    bufp->fullIData(oldp+22,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree[14]),32);
}

VL_ATTR_COLD void Vregister_tree_tb___024root__trace_full_1_sub_0(Vregister_tree_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vregister_tree_tb___024root__trace_full_1(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root__trace_full_1\n"); );
    // Init
    Vregister_tree_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vregister_tree_tb___024root*>(voidSelf);
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vregister_tree_tb___024root__trace_full_1_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vregister_tree_tb___024root__trace_full_1_sub_0(Vregister_tree_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root__trace_full_1_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+23,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                             [0U]),32);
    bufp->fullIData(oldp+24,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                             [1U]),32);
    bufp->fullIData(oldp+25,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                             [2U]),32);
    bufp->fullIData(oldp+26,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                             [3U]),32);
    bufp->fullIData(oldp+27,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                             [4U]),32);
    bufp->fullIData(oldp+28,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                             [5U]),32);
    bufp->fullIData(oldp+29,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                             [6U]),32);
    bufp->fullIData(oldp+30,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                             [7U]),32);
    bufp->fullIData(oldp+31,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                             [8U]),32);
    bufp->fullIData(oldp+32,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                             [9U]),32);
    bufp->fullIData(oldp+33,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                             [0xaU]),32);
    bufp->fullIData(oldp+34,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                             [0xbU]),32);
    bufp->fullIData(oldp+35,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                             [0xcU]),32);
    bufp->fullIData(oldp+36,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                             [0xdU]),32);
}

VL_ATTR_COLD void Vregister_tree_tb___024root__trace_full_2_sub_0(Vregister_tree_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vregister_tree_tb___024root__trace_full_2(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root__trace_full_2\n"); );
    // Init
    Vregister_tree_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vregister_tree_tb___024root*>(voidSelf);
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vregister_tree_tb___024root__trace_full_2_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vregister_tree_tb___024root__trace_full_2_sub_0(Vregister_tree_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root__trace_full_2_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+37,(vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                             [0xeU]),32);
    bufp->fullIData(oldp+38,(vlSelfRef.register_tree_tb__DOT__top_item),32);
    bufp->fullIData(oldp+39,(vlSelfRef.register_tree_tb__DOT__dut__DOT__unnamedblk2__DOT__k),32);
    bufp->fullIData(oldp+40,(vlSelfRef.register_tree_tb__DOT__dut__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j),32);
    bufp->fullIData(oldp+41,(vlSelfRef.register_tree_tb__DOT__dut__DOT__unnamedblk4__DOT__m),32);
    bufp->fullIData(oldp+42,(vlSelfRef.register_tree_tb__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__n),32);
    bufp->fullIData(oldp+43,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[0]),32);
    bufp->fullIData(oldp+44,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[1]),32);
    bufp->fullIData(oldp+45,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[2]),32);
    bufp->fullIData(oldp+46,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[3]),32);
    bufp->fullIData(oldp+47,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[4]),32);
    bufp->fullIData(oldp+48,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[5]),32);
    bufp->fullIData(oldp+49,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_parent[6]),32);
    bufp->fullIData(oldp+50,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[0]),32);
    bufp->fullIData(oldp+51,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[1]),32);
    bufp->fullIData(oldp+52,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[2]),32);
    bufp->fullIData(oldp+53,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[3]),32);
    bufp->fullIData(oldp+54,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[4]),32);
    bufp->fullIData(oldp+55,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[5]),32);
    bufp->fullIData(oldp+56,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_left_child[6]),32);
}

VL_ATTR_COLD void Vregister_tree_tb___024root__trace_full_3_sub_0(Vregister_tree_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vregister_tree_tb___024root__trace_full_3(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root__trace_full_3\n"); );
    // Init
    Vregister_tree_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vregister_tree_tb___024root*>(voidSelf);
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vregister_tree_tb___024root__trace_full_3_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vregister_tree_tb___024root__trace_full_3_sub_0(Vregister_tree_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root__trace_full_3_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+57,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[0]),32);
    bufp->fullIData(oldp+58,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[1]),32);
    bufp->fullIData(oldp+59,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[2]),32);
    bufp->fullIData(oldp+60,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[3]),32);
    bufp->fullIData(oldp+61,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[4]),32);
    bufp->fullIData(oldp+62,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[5]),32);
    bufp->fullIData(oldp+63,(vlSelfRef.register_tree_tb__DOT__dut__DOT__new_right_child[6]),32);
    bufp->fullBit(oldp+64,(vlSelfRef.register_tree_tb__DOT__clk));
    bufp->fullBit(oldp+65,(vlSelfRef.register_tree_tb__DOT__dut__DOT__level_indicator));
    bufp->fullIData(oldp+66,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                               ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                   ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [1U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [0U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                            ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [2U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [0U]))),32);
    bufp->fullIData(oldp+67,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                               ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                   ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [0U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [1U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                            ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [1U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [1U]))),32);
    bufp->fullIData(oldp+68,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                               ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                   ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [2U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [2U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                            ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [0U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [2U]))),32);
    bufp->fullBit(oldp+69,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__left_greater_than_right));
    bufp->fullBit(oldp+70,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__parent_less_than_left));
}

VL_ATTR_COLD void Vregister_tree_tb___024root__trace_full_4_sub_0(Vregister_tree_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vregister_tree_tb___024root__trace_full_4(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root__trace_full_4\n"); );
    // Init
    Vregister_tree_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vregister_tree_tb___024root*>(voidSelf);
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vregister_tree_tb___024root__trace_full_4_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vregister_tree_tb___024root__trace_full_4_sub_0(Vregister_tree_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root__trace_full_4_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+71,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__0__KET____DOT__comparator_inst__DOT__parent_less_than_right));
    bufp->fullIData(oldp+72,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                               ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                   ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [3U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [1U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                            ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [4U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [1U]))),32);
    bufp->fullIData(oldp+73,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                               ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                   ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [1U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [3U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                            ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [3U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [3U]))),32);
    bufp->fullIData(oldp+74,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                               ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                   ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [4U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [4U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                            ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [1U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [4U]))),32);
    bufp->fullBit(oldp+75,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__left_greater_than_right));
    bufp->fullBit(oldp+76,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__parent_less_than_left));
    bufp->fullBit(oldp+77,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__1__KET____DOT__comparator_inst__DOT__parent_less_than_right));
    bufp->fullIData(oldp+78,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                               ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                   ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [5U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [2U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                            ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [6U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [2U]))),32);
    bufp->fullIData(oldp+79,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                               ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                   ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [2U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [5U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                            ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [5U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [5U]))),32);
    bufp->fullIData(oldp+80,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                               ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                   ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [6U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [6U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                            ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [2U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [6U]))),32);
    bufp->fullBit(oldp+81,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__left_greater_than_right));
    bufp->fullBit(oldp+82,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__parent_less_than_left));
    bufp->fullBit(oldp+83,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__2__KET____DOT__comparator_inst__DOT__parent_less_than_right));
    bufp->fullIData(oldp+84,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                               ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                   ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [7U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [3U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                            ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [8U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [3U]))),32);
}

VL_ATTR_COLD void Vregister_tree_tb___024root__trace_full_5_sub_0(Vregister_tree_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vregister_tree_tb___024root__trace_full_5(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root__trace_full_5\n"); );
    // Init
    Vregister_tree_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vregister_tree_tb___024root*>(voidSelf);
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vregister_tree_tb___024root__trace_full_5_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vregister_tree_tb___024root__trace_full_5_sub_0(Vregister_tree_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root__trace_full_5_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+85,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                               ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                   ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [3U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [7U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                            ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [7U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [7U]))),32);
    bufp->fullIData(oldp+86,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                               ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                   ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [8U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [8U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                            ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [3U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [8U]))),32);
    bufp->fullBit(oldp+87,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__left_greater_than_right));
    bufp->fullBit(oldp+88,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__parent_less_than_left));
    bufp->fullBit(oldp+89,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__3__KET____DOT__comparator_inst__DOT__parent_less_than_right));
    bufp->fullIData(oldp+90,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                               ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                   ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [9U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [4U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                            ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [0xaU] : 
                                           vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [4U]))),32);
    bufp->fullIData(oldp+91,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                               ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                   ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [4U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [9U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                            ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [9U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [9U]))),32);
    bufp->fullIData(oldp+92,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                               ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                   ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [0xaU] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [0xaU]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                              ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                             [4U] : 
                                             vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                             [0xaU]))),32);
    bufp->fullBit(oldp+93,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__left_greater_than_right));
    bufp->fullBit(oldp+94,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__parent_less_than_left));
    bufp->fullBit(oldp+95,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__4__KET____DOT__comparator_inst__DOT__parent_less_than_right));
    bufp->fullIData(oldp+96,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                               ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                   ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [0xbU] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [5U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                            ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [0xcU] : 
                                           vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                           [5U]))),32);
    bufp->fullIData(oldp+97,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                               ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                   ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [5U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [0xbU]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                              ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                             [0xbU]
                                              : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                             [0xbU]))),32);
    bufp->fullIData(oldp+98,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                               ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                   ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [0xcU] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                  [0xcU]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                              ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                             [5U] : 
                                             vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                             [0xcU]))),32);
}

VL_ATTR_COLD void Vregister_tree_tb___024root__trace_full_6_sub_0(Vregister_tree_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vregister_tree_tb___024root__trace_full_6(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root__trace_full_6\n"); );
    // Init
    Vregister_tree_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vregister_tree_tb___024root*>(voidSelf);
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vregister_tree_tb___024root__trace_full_6_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vregister_tree_tb___024root__trace_full_6_sub_0(Vregister_tree_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_tree_tb___024root__trace_full_6_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+99,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__left_greater_than_right));
    bufp->fullBit(oldp+100,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__parent_less_than_left));
    bufp->fullBit(oldp+101,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__5__KET____DOT__comparator_inst__DOT__parent_less_than_right));
    bufp->fullIData(oldp+102,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                                ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                    ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                   [0xdU] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                   [6U]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                             ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                            [0xeU] : 
                                            vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                            [6U]))),32);
    bufp->fullIData(oldp+103,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                                ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                    ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                   [6U] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                   [0xdU]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                               ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                              [0xdU]
                                               : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                              [0xdU]))),32);
    bufp->fullIData(oldp+104,(((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__left_greater_than_right)
                                ? ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__parent_less_than_left)
                                    ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                   [0xeU] : vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                   [0xeU]) : ((IData)(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__parent_less_than_right)
                                               ? vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                              [6U] : 
                                              vlSelfRef.register_tree_tb__DOT__dut__DOT__tree
                                              [0xeU]))),32);
    bufp->fullBit(oldp+105,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__left_greater_than_right));
    bufp->fullBit(oldp+106,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__parent_less_than_left));
    bufp->fullBit(oldp+107,(vlSelfRef.register_tree_tb__DOT__dut__DOT__comparator_units__BRA__6__KET____DOT__comparator_inst__DOT__parent_less_than_right));
    bufp->fullIData(oldp+108,(vlSelfRef.register_tree_tb__DOT__dut__DOT__unnamedblk1__DOT__j),32);
}
