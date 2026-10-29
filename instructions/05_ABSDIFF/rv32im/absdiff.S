    .text
    .globl absdiff

# ABSDIFF: rd = |rs1 - rs2|, with 32-bit wrap semantics.
# Inputs:  a0 (rs1), a1 (rs2)
# Output:  a0 (rd)
absdiff:
    sub   t0, a0, a1
    bge   t0, zero, .Labsdiff_done
    sub   a0, zero, t0
.Labsdiff_done:
    jalr  zero, 0(ra)
