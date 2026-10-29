# 05_ABSDIFF/rv32im/

- 對應 Checkpoint:CP2
- 內容:RV32IM 組合語言實作與指令統計(僅允許 RV32IM)
- 實作檔案:`absdiff.S`
- 呼叫介面:輸入 `a0 = rs1`、`a1 = rs2`；結果以 32-bit 位元模式寫回 `a0`。
- 使用 RV32I 的 `sub`、`bge`、`jalr`；`t0` 暫存減法結果，減法與取絕對值皆自然保留低 32 位元。
