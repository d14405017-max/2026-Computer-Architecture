# 05_ABSDIFF/tests/

- 對應 Checkpoint:CP1–CP3
- 內容:測資與預期輸出(至少 10 組,含 3 組以上邊界值)
- 測試向量:`absdiff_vectors.csv`
- 欄位:`id`、`rs1`、`rs2`、`expected_rd_u32`、`case`
- `expected_rd_u32` 以無號十進位表示 32-bit 結果；減法及絕對值皆依 32-bit wrap 語意計算。
