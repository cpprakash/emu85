#include "../includes/Instructions.hpp"

Instructions::Instructions(void) {
  std::cout << "Instructions Constructor called" << std::endl;
  FillInstructionTableWithInstructions();
  FillInstructionTableWithInstructionsTwo();
}

void Instructions::FetchNextInstructions(void) {
  std::cout << "Hello World from FetchNextInstructions" << std::endl;
}
void Instructions::FillInstructionTableWithInstructions(void) {
  instruction_map.insert(std::make_pair(
      "INS_ACI_Data", std::make_pair(0xCE, MachineCycleEnum::TWO)));

  instruction_map.insert(std::make_pair(
      "INS_ACI_Data", std::make_pair(0xCE, MachineCycleEnum::TWO)));
  instruction_map.insert(
      std::make_pair("INS_ADC_A", std::make_pair(0x8F, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_ADC_B", std::make_pair(0x88, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_ADC_C", std::make_pair(0x89, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_ADC_D", std::make_pair(0x8A, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_ADC_E", std::make_pair(0x8B, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_ADC_H", std::make_pair(0x8C, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_ADC_L", std::make_pair(0x8D, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_ADC_M", std::make_pair(0x8E, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_ADD_A", std::make_pair(0x87, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_ADD_B", std::make_pair(0x80, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_ADD_C", std::make_pair(0x81, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_ADD_D", std::make_pair(0x82, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_ADD_E", std::make_pair(0x83, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_ADD_H", std::make_pair(0x84, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_ADD_L", std::make_pair(0x85, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_ADD_M", std::make_pair(0x86, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_ADI_Data", std::make_pair(0xC6, MachineCycleEnum::TWO)));
  instruction_map.insert(
      std::make_pair("INS_ANA_A", std::make_pair(0xA7, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_ANA_B", std::make_pair(0xA0, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_ANA_C", std::make_pair(0xA1, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_ANA_D", std::make_pair(0xA2, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_ANA_E", std::make_pair(0xA3, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_ANA_H", std::make_pair(0xA4, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_ANA_L", std::make_pair(0xA5, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_ANA_M", std::make_pair(0xA6, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_ANI_Data", std::make_pair(0xE6, MachineCycleEnum::TWO)));
  instruction_map.insert(std::make_pair(
      "INS_CALL_Label", std::make_pair(0xCD, MachineCycleEnum::THREE)));
  instruction_map.insert(std::make_pair(
      "INS_CC_Label", std::make_pair(0xDC, MachineCycleEnum::THREE)));
  instruction_map.insert(std::make_pair(
      "INS_CM_Label", std::make_pair(0xFC, MachineCycleEnum::THREE)));
  instruction_map.insert(
      std::make_pair("INS_CMA", std::make_pair(0x2F, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_CMC", std::make_pair(0x3F, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_CMP_A", std::make_pair(0xBF, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_CMP_B", std::make_pair(0xB8, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_CMP_C", std::make_pair(0xB9, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_CMP_D", std::make_pair(0xBA, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_CMP_E", std::make_pair(0xBB, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_CMP_H", std::make_pair(0xBC, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_CMP_L", std::make_pair(0xBD, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_CMP_M", std::make_pair(0xBD, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_CNC_Label", std::make_pair(0xD4, MachineCycleEnum::THREE)));
  instruction_map.insert(std::make_pair(
      "INS_CNZ_Label", std::make_pair(0xC4, MachineCycleEnum::THREE)));
  instruction_map.insert(std::make_pair(
      "INS_CP_Label", std::make_pair(0xF4, MachineCycleEnum::THREE)));
  instruction_map.insert(std::make_pair(
      "INS_CPE_Label", std::make_pair(0xEC, MachineCycleEnum::THREE)));
  instruction_map.insert(std::make_pair(
      "INS_CPI_Data", std::make_pair(0xFE, MachineCycleEnum::TWO)));
  instruction_map.insert(std::make_pair(
      "INS_CPO_Label", std::make_pair(0xE4, MachineCycleEnum::THREE)));
  instruction_map.insert(std::make_pair(
      "INS_CZ_Label", std::make_pair(0xCC, MachineCycleEnum::THREE)));
  instruction_map.insert(
      std::make_pair("INS_DAA", std::make_pair(0x27, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_DAD_B", std::make_pair(0x09, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_DAD_D", std::make_pair(0x19, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_DAD_H", std::make_pair(0x29, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_DAD_SP", std::make_pair(0x39, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_DCR_A", std::make_pair(0x3D, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_DCR_B", std::make_pair(0x05, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_DCR_C", std::make_pair(0x0D, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_DCR_D", std::make_pair(0x15, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_DCR_E", std::make_pair(0x1D, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_DCR_H", std::make_pair(0x25, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_DCR_L", std::make_pair(0x2D, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_DCR_M", std::make_pair(0x35, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_DCX_B", std::make_pair(0x0B, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_DCX_D", std::make_pair(0x1B, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_DCX_H", std::make_pair(0x2B, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_DCX_SP", std::make_pair(0x3B, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_DI", std::make_pair(0xF3, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_EI", std::make_pair(0xFB, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_HLT", std::make_pair(0x76, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_IN_Port-address", std::make_pair(0xDB, MachineCycleEnum::TWO)));
  instruction_map.insert(
      std::make_pair("INS_INR_A", std::make_pair(0x3C, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_INR_B", std::make_pair(0x04, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_INR_C", std::make_pair(0x0C, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_INR_D", std::make_pair(0x14, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_INR_E", std::make_pair(0x1C, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_INR_H", std::make_pair(0x24, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_INR_L", std::make_pair(0x2C, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_INR_M", std::make_pair(0x34, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_INX_B", std::make_pair(0x03, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_INX_D", std::make_pair(0x13, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_INX_H", std::make_pair(0x23, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_INX_SP", std::make_pair(0x33, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_JC_Label", std::make_pair(0xDA, MachineCycleEnum::THREE)));
  instruction_map.insert(std::make_pair(
      "INS_JM_Label", std::make_pair(0xFA, MachineCycleEnum::THREE)));
  instruction_map.insert(std::make_pair(
      "INS_JMP_Label", std::make_pair(0xC3, MachineCycleEnum::THREE)));
  instruction_map.insert(std::make_pair(
      "INS_JNC_Label", std::make_pair(0xD2, MachineCycleEnum::THREE)));
  instruction_map.insert(std::make_pair(
      "INS_JNZ_Label", std::make_pair(0xC2, MachineCycleEnum::THREE)));
  instruction_map.insert(std::make_pair(
      "INS_JP_Label", std::make_pair(0xF2, MachineCycleEnum::THREE)));
  instruction_map.insert(std::make_pair(
      "INS_JPE_Label", std::make_pair(0xEA, MachineCycleEnum::THREE)));
  instruction_map.insert(std::make_pair(
      "INS_JPO_Label", std::make_pair(0xE2, MachineCycleEnum::THREE)));
  instruction_map.insert(std::make_pair(
      "INS_JZ_Label", std::make_pair(0xCA, MachineCycleEnum::THREE)));
  instruction_map.insert(std::make_pair(
      "INS_LDA_Address", std::make_pair(0x3A, MachineCycleEnum::THREE)));
  instruction_map.insert(std::make_pair(
      "INS_LDAX_B", std::make_pair(0x0A, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_LDAX_D", std::make_pair(0x1A, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_LHLD_Address", std::make_pair(0x2A, MachineCycleEnum::THREE)));
  instruction_map.insert(std::make_pair(
      "INS_LXI_B", std::make_pair(0x01, MachineCycleEnum::THREE)));
  instruction_map.insert(std::make_pair(
      "INS_LXI_D", std::make_pair(0x11, MachineCycleEnum::THREE)));
  instruction_map.insert(std::make_pair(
      "INS_LXI_H", std::make_pair(0x21, MachineCycleEnum::THREE)));
  instruction_map.insert(std::make_pair(
      "INS_LXI_SP", std::make_pair(0x31, MachineCycleEnum::THREE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_A_A", std::make_pair(0x7F, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_A_B", std::make_pair(0x78, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_A_C", std::make_pair(0x79, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_A_D", std::make_pair(0x7A, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_A_E", std::make_pair(0x7B, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_A_H", std::make_pair(0x7C, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_A_L", std::make_pair(0x7D, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_A_M", std::make_pair(0x7E, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_B_A", std::make_pair(0x47, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_B_B", std::make_pair(0x40, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_B_C", std::make_pair(0x41, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_B_D", std::make_pair(0x42, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_B_E", std::make_pair(0x43, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_B_H", std::make_pair(0x44, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_B_L", std::make_pair(0x45, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_B_M", std::make_pair(0x46, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_C_A", std::make_pair(0x4F, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_C_B", std::make_pair(0x48, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_C_C", std::make_pair(0x49, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_C_D", std::make_pair(0x4A, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_C_E", std::make_pair(0x4B, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_C_H", std::make_pair(0x4C, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_C_L", std::make_pair(0x4D, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_C_M", std::make_pair(0x4E, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_D_A", std::make_pair(0x57, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_D_B", std::make_pair(0x50, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_D_C", std::make_pair(0x51, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_D_D", std::make_pair(0x52, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_D_E", std::make_pair(0x53, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_D_H", std::make_pair(0x54, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_D_L", std::make_pair(0x55, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_D_M", std::make_pair(0x56, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_E_A", std::make_pair(0x5F, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_E_B", std::make_pair(0x58, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_E_C", std::make_pair(0x59, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_E_D", std::make_pair(0x5A, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_E_E", std::make_pair(0x5B, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_E_H", std::make_pair(0x5C, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_E_L", std::make_pair(0x5D, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_E_M", std::make_pair(0x5E, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_H_A", std::make_pair(0x67, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_H_B", std::make_pair(0x60, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_H_C", std::make_pair(0x61, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_H_D", std::make_pair(0x62, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_H_E", std::make_pair(0x63, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_H_H", std::make_pair(0x64, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_H_L", std::make_pair(0x65, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_H_M", std::make_pair(0x66, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_L_A", std::make_pair(0x6F, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_L_B", std::make_pair(0x68, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_L_C", std::make_pair(0x69, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_L_D", std::make_pair(0x6A, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_L_E", std::make_pair(0x6B, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_L_H", std::make_pair(0x6C, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_L_L", std::make_pair(0x6D, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_L_M", std::make_pair(0x6E, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_M_A", std::make_pair(0x77, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_M_B", std::make_pair(0x70, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_M_C", std::make_pair(0x71, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_M_D", std::make_pair(0x72, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_M_E", std::make_pair(0x73, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_M_H", std::make_pair(0x74, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MOV_M_L", std::make_pair(0x75, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_MVI_A_Data", std::make_pair(0x3E, MachineCycleEnum::TWO)));
  instruction_map.insert(std::make_pair(
      "INS_MVI_B_Data", std::make_pair(0x06, MachineCycleEnum::TWO)));
  instruction_map.insert(std::make_pair(
      "INS_MVI_C_Data", std::make_pair(0x0E, MachineCycleEnum::TWO)));
  instruction_map.insert(std::make_pair(
      "INS_MVI_D_Data", std::make_pair(0x16, MachineCycleEnum::TWO)));
  instruction_map.insert(std::make_pair(
      "INS_MVI_E_Data", std::make_pair(0x1E, MachineCycleEnum::TWO)));
  instruction_map.insert(std::make_pair(
      "INS_MVI_H_Data", std::make_pair(0x26, MachineCycleEnum::TWO)));
  instruction_map.insert(std::make_pair(
      "INS_MVI_L_Data", std::make_pair(0x2E, MachineCycleEnum::TWO)));
  instruction_map.insert(std::make_pair(
      "INS_MVI_M_Data", std::make_pair(0x36, MachineCycleEnum::TWO)));
  instruction_map.insert(
      std::make_pair("INS_NOP", std::make_pair(0x00, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_ORA_A", std::make_pair(0xB7, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_ORA_B", std::make_pair(0xB0, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_ORA_C", std::make_pair(0xB1, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_ORA_D", std::make_pair(0xB2, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_ORA_E", std::make_pair(0xB3, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_ORA_H", std::make_pair(0xB4, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_ORA_L", std::make_pair(0xB5, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_ORA_M", std::make_pair(0xB6, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_ORI_Data", std::make_pair(0xF6, MachineCycleEnum::TWO)));
  instruction_map.insert(std::make_pair(
      "INS_OUT_Port-Address", std::make_pair(0xD3, MachineCycleEnum::TWO)));
  instruction_map.insert(
      std::make_pair("INS_PCHL", std::make_pair(0xE9, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_POP_B", std::make_pair(0xC1, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_POP_D", std::make_pair(0xD1, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_POP_H", std::make_pair(0xE1, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_POP_PSW", std::make_pair(0xF1, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_PUSH_B", std::make_pair(0xC5, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_PUSH_D", std::make_pair(0xD5, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_PUSH_H", std::make_pair(0xE5, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_PUSH_PSW", std::make_pair(0xF5, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_RAL", std::make_pair(0x17, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_RAR", std::make_pair(0x1F, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_RC", std::make_pair(0xD8, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_RET", std::make_pair(0xC9, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_RIM", std::make_pair(0x20, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_RLC", std::make_pair(0x07, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_RM", std::make_pair(0xF8, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_RNC", std::make_pair(0xD0, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_RNZ", std::make_pair(0xC0, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_RP", std::make_pair(0xF0, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_RPE", std::make_pair(0xE8, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_RPO", std::make_pair(0xE0, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_RRC", std::make_pair(0x0F, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_RST_0", std::make_pair(0xC7, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_RST_1", std::make_pair(0xCF, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_RST_2", std::make_pair(0xD7, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_RST_3", std::make_pair(0xDF, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_RST_4", std::make_pair(0xE7, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_RST_5", std::make_pair(0xEF, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_RST_6", std::make_pair(0xF7, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_RST_7", std::make_pair(0xFF, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_RZ", std::make_pair(0xC8, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_SBB_A", std::make_pair(0x9F, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_SBB_B", std::make_pair(0x98, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_SBB_C", std::make_pair(0x99, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_SBB_D", std::make_pair(0x9A, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_SBB_E", std::make_pair(0x9B, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_SBB_H", std::make_pair(0x9C, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_SBB_L", std::make_pair(0x9D, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_SBB_M", std::make_pair(0x9E, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_SBI_Data", std::make_pair(0xDE, MachineCycleEnum::TWO)));
  instruction_map.insert(std::make_pair(
      "INS_SHLD_Address", std::make_pair(0x22, MachineCycleEnum::THREE)));
  instruction_map.insert(
      std::make_pair("INS_SIM", std::make_pair(0x30, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_SPHL", std::make_pair(0xF9, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_STA_Address", std::make_pair(0x32, MachineCycleEnum::THREE)));
  instruction_map.insert(std::make_pair(
      "INS_STAX_B", std::make_pair(0x02, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_STAX_D", std::make_pair(0x12, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_STC", std::make_pair(0x37, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_SUB_A", std::make_pair(0x97, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_SUB_B", std::make_pair(0x90, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_SUB_C", std::make_pair(0x91, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_SUB_D", std::make_pair(0x92, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_SUB_E", std::make_pair(0x93, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_SUB_H", std::make_pair(0x94, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_SUB_L", std::make_pair(0x95, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_SUB_M", std::make_pair(0x96, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_SUI_Data", std::make_pair(0xD6, MachineCycleEnum::TWO)));
  instruction_map.insert(
      std::make_pair("INS_XCHG", std::make_pair(0xEB, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_XRA_A", std::make_pair(0xAF, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_XRA_B", std::make_pair(0xA8, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_XRA_C", std::make_pair(0xA9, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_XRA_D", std::make_pair(0xAA, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_XRA_E", std::make_pair(0xAB, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_XRA_H", std::make_pair(0xAC, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_XRA_L", std::make_pair(0xAD, MachineCycleEnum::ONE)));
  instruction_map.insert(
      std::make_pair("INS_XRA_M", std::make_pair(0xAE, MachineCycleEnum::ONE)));
  instruction_map.insert(std::make_pair(
      "INS_XRI_Data", std::make_pair(0xEE, MachineCycleEnum::TWO)));
  instruction_map.insert(
      std::make_pair("INS_XTHL", std::make_pair(0xE3, MachineCycleEnum::ONE)));
}

/***
 * Trying to fix ENUMS
 */
void Instructions::FillInstructionTableWithInstructionsTwo(void) {
  // instruction_map2.insert(std::make_pair("INS_ACI_Data", 0xCE));

  instruction_map2.insert(std::make_pair("INS_ACI_Data", 0xCE));
  instruction_map2.insert(std::make_pair("INS_ADC_A", 0x8F));
  instruction_map2.insert(std::make_pair("INS_ADC_B", 0x88));
  instruction_map2.insert(std::make_pair("INS_ADC_C", 0x89));
  instruction_map2.insert(std::make_pair("INS_ADC_D", 0x8A));
  instruction_map2.insert(std::make_pair("INS_ADC_E", 0x8B));
  instruction_map2.insert(std::make_pair("INS_ADC_H", 0x8C));
  instruction_map2.insert(std::make_pair("INS_ADC_L", 0x8D));
  instruction_map2.insert(std::make_pair("INS_ADC_M", 0x8E));
  instruction_map2.insert(std::make_pair("INS_ADD_A", 0x87));
  instruction_map2.insert(std::make_pair("INS_ADD_B", 0x80));
  instruction_map2.insert(std::make_pair("INS_ADD_C", 0x81));
  instruction_map2.insert(std::make_pair("INS_ADD_D", 0x82));
  instruction_map2.insert(std::make_pair("INS_ADD_E", 0x83));
  instruction_map2.insert(std::make_pair("INS_ADD_H", 0x84));
  instruction_map2.insert(std::make_pair("INS_ADD_L", 0x85));
  instruction_map2.insert(std::make_pair("INS_ADD_M", 0x86));
  instruction_map2.insert(std::make_pair("INS_ADI_Data", 0xC6));
  instruction_map2.insert(std::make_pair("INS_ANA_A", 0xA7));
  instruction_map2.insert(std::make_pair("INS_ANA_B", 0xA0));
  instruction_map2.insert(std::make_pair("INS_ANA_C", 0xA1));
  instruction_map2.insert(std::make_pair("INS_ANA_D", 0xA2));
  instruction_map2.insert(std::make_pair("INS_ANA_E", 0xA3));
  instruction_map2.insert(std::make_pair("INS_ANA_H", 0xA4));
  instruction_map2.insert(std::make_pair("INS_ANA_L", 0xA5));
  instruction_map2.insert(std::make_pair("INS_ANA_M", 0xA6));
  instruction_map2.insert(std::make_pair("INS_ANI_Data", 0xE6));
  instruction_map2.insert(std::make_pair("INS_CALL_Label", 0xCD));
  instruction_map2.insert(std::make_pair("INS_CC_Label", 0xDC));
  instruction_map2.insert(std::make_pair("INS_CM_Label", 0xFC));
  instruction_map2.insert(std::make_pair("INS_CMA", 0x2F));
  instruction_map2.insert(std::make_pair("INS_CMC", 0x3F));
  instruction_map2.insert(std::make_pair("INS_CMP_A", 0xBF));
  instruction_map2.insert(std::make_pair("INS_CMP_B", 0xB8));
  instruction_map2.insert(std::make_pair("INS_CMP_C", 0xB9));
  instruction_map2.insert(std::make_pair("INS_CMP_D", 0xBA));
  instruction_map2.insert(std::make_pair("INS_CMP_E", 0xBB));
  instruction_map2.insert(std::make_pair("INS_CMP_H", 0xBC));
  instruction_map2.insert(std::make_pair("INS_CMP_L", 0xBD));
  instruction_map2.insert(std::make_pair("INS_CMP_M", 0xBD));
  instruction_map2.insert(std::make_pair("INS_CNC_Label", 0xD4));
  instruction_map2.insert(std::make_pair("INS_CNZ_Label", 0xC4));
  instruction_map2.insert(std::make_pair("INS_CP_Label", 0xF4));
  instruction_map2.insert(std::make_pair("INS_CPE_Label", 0xEC));
  instruction_map2.insert(std::make_pair("INS_CPI_Data", 0xFE));
  instruction_map2.insert(std::make_pair("INS_CPO_Label", 0xE4));
  instruction_map2.insert(std::make_pair("INS_CZ_Label", 0xCC));
  instruction_map2.insert(std::make_pair("INS_DAA", 0x27));
  instruction_map2.insert(std::make_pair("INS_DAD_B", 0x09));
  instruction_map2.insert(std::make_pair("INS_DAD_D", 0x19));
  instruction_map2.insert(std::make_pair("INS_DAD_H", 0x29));
  instruction_map2.insert(std::make_pair("INS_DAD_SP", 0x39));
  instruction_map2.insert(std::make_pair("INS_DCR_A", 0x3D));
  instruction_map2.insert(std::make_pair("INS_DCR_B", 0x05));
  instruction_map2.insert(std::make_pair("INS_DCR_C", 0x0D));
  instruction_map2.insert(std::make_pair("INS_DCR_D", 0x15));
  instruction_map2.insert(std::make_pair("INS_DCR_E", 0x1D));
  instruction_map2.insert(std::make_pair("INS_DCR_H", 0x25));
  instruction_map2.insert(std::make_pair("INS_DCR_L", 0x2D));
  instruction_map2.insert(std::make_pair("INS_DCR_M", 0x35));
  instruction_map2.insert(std::make_pair("INS_DCX_B", 0x0B));
  instruction_map2.insert(std::make_pair("INS_DCX_D", 0x1B));
  instruction_map2.insert(std::make_pair("INS_DCX_H", 0x2B));
  instruction_map2.insert(std::make_pair("INS_DCX_SP", 0x3B));
  instruction_map2.insert(std::make_pair("INS_DI", 0xF3));
  instruction_map2.insert(std::make_pair("INS_EI", 0xFB));
  instruction_map2.insert(std::make_pair("INS_HLT", 0x76));
  instruction_map2.insert(std::make_pair("INS_IN_Port-address", 0xDB));
  instruction_map2.insert(std::make_pair("INS_INR_A", 0x3C));
  instruction_map2.insert(std::make_pair("INS_INR_B", 0x04));
  instruction_map2.insert(std::make_pair("INS_INR_C", 0x0C));
  instruction_map2.insert(std::make_pair("INS_INR_D", 0x14));
  instruction_map2.insert(std::make_pair("INS_INR_E", 0x1C));
  instruction_map2.insert(std::make_pair("INS_INR_H", 0x24));
  instruction_map2.insert(std::make_pair("INS_INR_L", 0x2C));
  instruction_map2.insert(std::make_pair("INS_INR_M", 0x34));
  instruction_map2.insert(std::make_pair("INS_INX_B", 0x03));
  instruction_map2.insert(std::make_pair("INS_INX_D", 0x13));
  instruction_map2.insert(std::make_pair("INS_INX_H", 0x23));
  instruction_map2.insert(std::make_pair("INS_INX_SP", 0x33));
  instruction_map2.insert(std::make_pair("INS_JC_Label", 0xDA));
  instruction_map2.insert(std::make_pair("INS_JM_Label", 0xFA));
  instruction_map2.insert(std::make_pair("INS_JMP_Label", 0xC3));
  instruction_map2.insert(std::make_pair("INS_JNC_Label", 0xD2));
  instruction_map2.insert(std::make_pair("INS_JNZ_Label", 0xC2));
  instruction_map2.insert(std::make_pair("INS_JP_Label", 0xF2));
  instruction_map2.insert(std::make_pair("INS_JPE_Label", 0xEA));
  instruction_map2.insert(std::make_pair("INS_JPO_Label", 0xE2));
  instruction_map2.insert(std::make_pair("INS_JZ_Label", 0xCA));
  instruction_map2.insert(std::make_pair("INS_LDA_Address", 0x3A));
  instruction_map2.insert(std::make_pair("INS_LDAX_B", 0x0A));
  instruction_map2.insert(std::make_pair("INS_LDAX_D", 0x1A));
  instruction_map2.insert(std::make_pair("INS_LHLD_Address", 0x2A));
  instruction_map2.insert(std::make_pair("INS_LXI_B", 0x01));
  instruction_map2.insert(std::make_pair("INS_LXI_D", 0x11));
  instruction_map2.insert(std::make_pair("INS_LXI_H", 0x21));
  instruction_map2.insert(std::make_pair("INS_LXI_SP", 0x31));
  instruction_map2.insert(std::make_pair("INS_MOV_A_A", 0x7F));
  instruction_map2.insert(std::make_pair("INS_MOV_A_B", 0x78));
  instruction_map2.insert(std::make_pair("INS_MOV_A_C", 0x79));
  instruction_map2.insert(std::make_pair("INS_MOV_A_D", 0x7A));
  instruction_map2.insert(std::make_pair("INS_MOV_A_E", 0x7B));
  instruction_map2.insert(std::make_pair("INS_MOV_A_H", 0x7C));
  instruction_map2.insert(std::make_pair("INS_MOV_A_L", 0x7D));
  instruction_map2.insert(std::make_pair("INS_MOV_A_M", 0x7E));
  instruction_map2.insert(std::make_pair("INS_MOV_B_A", 0x47));
  instruction_map2.insert(std::make_pair("INS_MOV_B_B", 0x40));
  instruction_map2.insert(std::make_pair("INS_MOV_B_C", 0x41));
  instruction_map2.insert(std::make_pair("INS_MOV_B_D", 0x42));
  instruction_map2.insert(std::make_pair("INS_MOV_B_E", 0x43));
  instruction_map2.insert(std::make_pair("INS_MOV_B_H", 0x44));
  instruction_map2.insert(std::make_pair("INS_MOV_B_L", 0x45));
  instruction_map2.insert(std::make_pair("INS_MOV_B_M", 0x46));
  instruction_map2.insert(std::make_pair("INS_MOV_C_A", 0x4F));
  instruction_map2.insert(std::make_pair("INS_MOV_C_B", 0x48));
  instruction_map2.insert(std::make_pair("INS_MOV_C_C", 0x49));
  instruction_map2.insert(std::make_pair("INS_MOV_C_D", 0x4A));
  instruction_map2.insert(std::make_pair("INS_MOV_C_E", 0x4B));
  instruction_map2.insert(std::make_pair("INS_MOV_C_H", 0x4C));
  instruction_map2.insert(std::make_pair("INS_MOV_C_L", 0x4D));
  instruction_map2.insert(std::make_pair("INS_MOV_C_M", 0x4E));
  instruction_map2.insert(std::make_pair("INS_MOV_D_A", 0x57));
  instruction_map2.insert(std::make_pair("INS_MOV_D_B", 0x50));
  instruction_map2.insert(std::make_pair("INS_MOV_D_C", 0x51));
  instruction_map2.insert(std::make_pair("INS_MOV_D_D", 0x52));
  instruction_map2.insert(std::make_pair("INS_MOV_D_E", 0x53));
  instruction_map2.insert(std::make_pair("INS_MOV_D_H", 0x54));
  instruction_map2.insert(std::make_pair("INS_MOV_D_L", 0x55));
  instruction_map2.insert(std::make_pair("INS_MOV_D_M", 0x56));
  instruction_map2.insert(std::make_pair("INS_MOV_E_A", 0x5F));
  instruction_map2.insert(std::make_pair("INS_MOV_E_B", 0x58));
  instruction_map2.insert(std::make_pair("INS_MOV_E_C", 0x59));
  instruction_map2.insert(std::make_pair("INS_MOV_E_D", 0x5A));
  instruction_map2.insert(std::make_pair("INS_MOV_E_E", 0x5B));
  instruction_map2.insert(std::make_pair("INS_MOV_E_H", 0x5C));
  instruction_map2.insert(std::make_pair("INS_MOV_E_L", 0x5D));
  instruction_map2.insert(std::make_pair("INS_MOV_E_M", 0x5E));
  instruction_map2.insert(std::make_pair("INS_MOV_H_A", 0x67));
  instruction_map2.insert(std::make_pair("INS_MOV_H_B", 0x60));
  instruction_map2.insert(std::make_pair("INS_MOV_H_C", 0x61));
  instruction_map2.insert(std::make_pair("INS_MOV_H_D", 0x62));
  instruction_map2.insert(std::make_pair("INS_MOV_H_E", 0x63));
  instruction_map2.insert(std::make_pair("INS_MOV_H_H", 0x64));
  instruction_map2.insert(std::make_pair("INS_MOV_H_L", 0x65));
  instruction_map2.insert(std::make_pair("INS_MOV_H_M", 0x66));
  instruction_map2.insert(std::make_pair("INS_MOV_L_A", 0x6F));
  instruction_map2.insert(std::make_pair("INS_MOV_L_B", 0x68));
  instruction_map2.insert(std::make_pair("INS_MOV_L_C", 0x69));
  instruction_map2.insert(std::make_pair("INS_MOV_L_D", 0x6A));
  instruction_map2.insert(std::make_pair("INS_MOV_L_E", 0x6B));
  instruction_map2.insert(std::make_pair("INS_MOV_L_H", 0x6C));
  instruction_map2.insert(std::make_pair("INS_MOV_L_L", 0x6D));
  instruction_map2.insert(std::make_pair("INS_MOV_L_M", 0x6E));
  instruction_map2.insert(std::make_pair("INS_MOV_M_A", 0x77));
  instruction_map2.insert(std::make_pair("INS_MOV_M_B", 0x70));
  instruction_map2.insert(std::make_pair("INS_MOV_M_C", 0x71));
  instruction_map2.insert(std::make_pair("INS_MOV_M_D", 0x72));
  instruction_map2.insert(std::make_pair("INS_MOV_M_E", 0x73));
  instruction_map2.insert(std::make_pair("INS_MOV_M_H", 0x74));
  instruction_map2.insert(std::make_pair("INS_MOV_M_L", 0x75));
  instruction_map2.insert(std::make_pair("INS_MVI_A_Data", 0x3E));
  instruction_map2.insert(std::make_pair("INS_MVI_B_Data", 0x06));
  instruction_map2.insert(std::make_pair("INS_MVI_C_Data", 0x0E));
  instruction_map2.insert(std::make_pair("INS_MVI_D_Data", 0x16));
  instruction_map2.insert(std::make_pair("INS_MVI_E_Data", 0x1E));
  instruction_map2.insert(std::make_pair("INS_MVI_H_Data", 0x26));
  instruction_map2.insert(std::make_pair("INS_MVI_L_Data", 0x2E));
  instruction_map2.insert(std::make_pair("INS_MVI_M_Data", 0x36));
  instruction_map2.insert(std::make_pair("INS_NOP", 0x00));
  instruction_map2.insert(std::make_pair("INS_ORA_A", 0xB7));
  instruction_map2.insert(std::make_pair("INS_ORA_B", 0xB0));
  instruction_map2.insert(std::make_pair("INS_ORA_C", 0xB1));
  instruction_map2.insert(std::make_pair("INS_ORA_D", 0xB2));
  instruction_map2.insert(std::make_pair("INS_ORA_E", 0xB3));
  instruction_map2.insert(std::make_pair("INS_ORA_H", 0xB4));
  instruction_map2.insert(std::make_pair("INS_ORA_L", 0xB5));
  instruction_map2.insert(std::make_pair("INS_ORA_M", 0xB6));
  instruction_map2.insert(std::make_pair("INS_ORI_Data", 0xF6));
  instruction_map2.insert(std::make_pair("INS_OUT_Port-Address", 0xD3));
  instruction_map2.insert(std::make_pair("INS_PCHL", 0xE9));
  instruction_map2.insert(std::make_pair("INS_POP_B", 0xC1));
  instruction_map2.insert(std::make_pair("INS_POP_D", 0xD1));
  instruction_map2.insert(std::make_pair("INS_POP_H", 0xE1));
  instruction_map2.insert(std::make_pair("INS_POP_PSW", 0xF1));
  instruction_map2.insert(std::make_pair("INS_PUSH_B", 0xC5));
  instruction_map2.insert(std::make_pair("INS_PUSH_D", 0xD5));
  instruction_map2.insert(std::make_pair("INS_PUSH_H", 0xE5));
  instruction_map2.insert(std::make_pair("INS_PUSH_PSW", 0xF5));
  instruction_map2.insert(std::make_pair("INS_RAL", 0x17));
  instruction_map2.insert(std::make_pair("INS_RAR", 0x1F));
  instruction_map2.insert(std::make_pair("INS_RC", 0xD8));
  instruction_map2.insert(std::make_pair("INS_RET", 0xC9));
  instruction_map2.insert(std::make_pair("INS_RIM", 0x20));
  instruction_map2.insert(std::make_pair("INS_RLC", 0x07));
  instruction_map2.insert(std::make_pair("INS_RM", 0xF8));
  instruction_map2.insert(std::make_pair("INS_RNC", 0xD0));
  instruction_map2.insert(std::make_pair("INS_RNZ", 0xC0));
  instruction_map2.insert(std::make_pair("INS_RP", 0xF0));
  instruction_map2.insert(std::make_pair("INS_RPE", 0xE8));
  instruction_map2.insert(std::make_pair("INS_RPO", 0xE0));
  instruction_map2.insert(std::make_pair("INS_RRC", 0x0F));
  instruction_map2.insert(std::make_pair("INS_RST_0", 0xC7));
  instruction_map2.insert(std::make_pair("INS_RST_1", 0xCF));
  instruction_map2.insert(std::make_pair("INS_RST_2", 0xD7));
  instruction_map2.insert(std::make_pair("INS_RST_3", 0xDF));
  instruction_map2.insert(std::make_pair("INS_RST_4", 0xE7));
  instruction_map2.insert(std::make_pair("INS_RST_5", 0xEF));
  instruction_map2.insert(std::make_pair("INS_RST_6", 0xF7));
  instruction_map2.insert(std::make_pair("INS_RST_7", 0xFF));
  instruction_map2.insert(std::make_pair("INS_RZ", 0xC8));
  instruction_map2.insert(std::make_pair("INS_SBB_A", 0x9F));
  instruction_map2.insert(std::make_pair("INS_SBB_B", 0x98));
  instruction_map2.insert(std::make_pair("INS_SBB_C", 0x99));
  instruction_map2.insert(std::make_pair("INS_SBB_D", 0x9A));
  instruction_map2.insert(std::make_pair("INS_SBB_E", 0x9B));
  instruction_map2.insert(std::make_pair("INS_SBB_H", 0x9C));
  instruction_map2.insert(std::make_pair("INS_SBB_L", 0x9D));
  instruction_map2.insert(std::make_pair("INS_SBB_M", 0x9E));
  instruction_map2.insert(std::make_pair("INS_SBI_Data", 0xDE));
  instruction_map2.insert(std::make_pair("INS_SHLD_Address", 0x22));
  instruction_map2.insert(std::make_pair("INS_SIM", 0x30));
  instruction_map2.insert(std::make_pair("INS_SPHL", 0xF9));
  instruction_map2.insert(std::make_pair("INS_STA_Address", 0x32));
  instruction_map2.insert(std::make_pair("INS_STAX_B", 0x02));
  instruction_map2.insert(std::make_pair("INS_STAX_D", 0x12));
  instruction_map2.insert(std::make_pair("INS_STC", 0x37));
  instruction_map2.insert(std::make_pair("INS_SUB_A", 0x97));
  instruction_map2.insert(std::make_pair("INS_SUB_B", 0x90));
  instruction_map2.insert(std::make_pair("INS_SUB_C", 0x91));
  instruction_map2.insert(std::make_pair("INS_SUB_D", 0x92));
  instruction_map2.insert(std::make_pair("INS_SUB_E", 0x93));
  instruction_map2.insert(std::make_pair("INS_SUB_H", 0x94));
  instruction_map2.insert(std::make_pair("INS_SUB_L", 0x95));
  instruction_map2.insert(std::make_pair("INS_SUB_M", 0x96));
  instruction_map2.insert(std::make_pair("INS_SUI_Data", 0xD6));
  instruction_map2.insert(std::make_pair("INS_XCHG", 0xEB));
  instruction_map2.insert(std::make_pair("INS_XRA_A", 0xAF));
  instruction_map2.insert(std::make_pair("INS_XRA_B", 0xA8));
  instruction_map2.insert(std::make_pair("INS_XRA_C", 0xA9));
  instruction_map2.insert(std::make_pair("INS_XRA_D", 0xAA));
  instruction_map2.insert(std::make_pair("INS_XRA_E", 0xAB));
  instruction_map2.insert(std::make_pair("INS_XRA_H", 0xAC));
  instruction_map2.insert(std::make_pair("INS_XRA_L", 0xAD));
  instruction_map2.insert(std::make_pair("INS_XRA_M", 0xAE));
  instruction_map2.insert(std::make_pair("INS_XRI_Data", 0xEE));
  instruction_map2.insert(std::make_pair("INS_XTHL", 0xE3));
}