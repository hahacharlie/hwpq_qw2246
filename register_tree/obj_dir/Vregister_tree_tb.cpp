// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vregister_tree_tb__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vregister_tree_tb::Vregister_tree_tb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vregister_tree_tb__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vregister_tree_tb::Vregister_tree_tb(const char* _vcname__)
    : Vregister_tree_tb(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vregister_tree_tb::~Vregister_tree_tb() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vregister_tree_tb___024root___eval_debug_assertions(Vregister_tree_tb___024root* vlSelf);
#endif  // VL_DEBUG
void Vregister_tree_tb___024root___eval_static(Vregister_tree_tb___024root* vlSelf);
void Vregister_tree_tb___024root___eval_initial(Vregister_tree_tb___024root* vlSelf);
void Vregister_tree_tb___024root___eval_settle(Vregister_tree_tb___024root* vlSelf);
void Vregister_tree_tb___024root___eval(Vregister_tree_tb___024root* vlSelf);

void Vregister_tree_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vregister_tree_tb::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vregister_tree_tb___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vregister_tree_tb___024root___eval_static(&(vlSymsp->TOP));
        Vregister_tree_tb___024root___eval_initial(&(vlSymsp->TOP));
        Vregister_tree_tb___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vregister_tree_tb___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vregister_tree_tb::eval_end_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step Vregister_tree_tb::eval_end_step\n"); );
#ifdef VM_TRACE
    // Tracing
    if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) vlSymsp->_traceDump();
#endif  // VM_TRACE
}

//============================================================
// Events and timing
bool Vregister_tree_tb::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vregister_tree_tb::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vregister_tree_tb::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vregister_tree_tb___024root___eval_final(Vregister_tree_tb___024root* vlSelf);

VL_ATTR_COLD void Vregister_tree_tb::final() {
    Vregister_tree_tb___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vregister_tree_tb::hierName() const { return vlSymsp->name(); }
const char* Vregister_tree_tb::modelName() const { return "Vregister_tree_tb"; }
unsigned Vregister_tree_tb::threads() const { return 8; }
void Vregister_tree_tb::prepareClone() const { contextp()->prepareClone(); }
void Vregister_tree_tb::atClone() const {
    vlSymsp->__Vm_threadPoolp = static_cast<VlThreadPool*>(contextp()->threadPoolpOnClone());
}
std::unique_ptr<VerilatedTraceConfig> Vregister_tree_tb::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{true, false, false}};
};

//============================================================
// Trace configuration

void Vregister_tree_tb___024root__trace_decl_types(VerilatedVcd* tracep);

void Vregister_tree_tb___024root__trace_init_top(Vregister_tree_tb___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vregister_tree_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vregister_tree_tb___024root*>(voidSelf);
    Vregister_tree_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    if (strlen(vlSymsp->name())) tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vregister_tree_tb___024root__trace_decl_types(tracep);
    Vregister_tree_tb___024root__trace_init_top(vlSelf, tracep);
    if (strlen(vlSymsp->name())) tracep->popPrefix();
}

VL_ATTR_COLD void Vregister_tree_tb___024root__trace_register(Vregister_tree_tb___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vregister_tree_tb::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vregister_tree_tb::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vregister_tree_tb___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
