add x2, x0, x1
sll x1, x2, x2
or x2, x2, x1
andi x2, x1, 16
addi x3, x2, -243
lw x8, 0(x7)
lb x2, 4(x3)
sb x2, 8(x3)
sub x4, x2, x3
and x4, x2, x3
ori x3, x2, 15
srl x3, x2, 2
bne x3, x29, 21
beq x3, x13, 20
bne x3, x13, 20