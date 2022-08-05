# Brainfuck Language

## Grammar

```
S ::= [statement S];
statement ::= '>'
    | '<'
    | '+'
    | '-'
    | '.'
    | ','
    | '[' + S + ']';
```

## Assembly Code

### Assumptions

* only integer operations, i.e. 4 byte
* `r0` stores a `1`
* `r1` stores a pointer to the current cell
* `r2` stores the contents of the current cell

### Operations

* `add rz, rx, ry` -> add `rx` and `ry`, store in `rz`
* `addi rz, rx, immediate` -> add `immediate` to `rx`, store in `rz`
* `sub rz, rx, ry` -> subtract `ry` from `rx`, store in `rz`
* `subi rz, rx, immediate` -> subtract `immediate` from `rx`, store in `rz`
* `load rz, offset(rx)` -> load value from address `[rx] + offset` and store in `rz`
* `store rz, offset(rx)` -> store content of `rz` at address `[rx] + offset`
* `jmp label` -> jump to `label`
* `jz rx, label` -> jump to `label` if `rx` is zero
* `read rx` -> read character from `stdin`, store in `rx`
* `write rx` -> write content of `rx` to `stdout`