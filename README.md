# MIT6.1810

## Dependencies

```bash
sudo apt-get install git build-essential gdb-multiarch qemu-system-misc gcc-riscv64-linux-gnu binutils-riscv64-linux-gnu
```

## Usage

run qemu

```bash
make qemu
```

exit qemu

```bash
Ctrl + a x
```

## Lab Utilities

run all tests

```bash
make grade
# Or
./grade-lab-util
```

run the grade tests for one assignment

```bash
make GRADEFLAGS=<cmd> grade
./grade-lab-util <cmd>

# eg
make GRADEFLAGS=sleep grade
./grade-lab-util sleep
```

## Lab System calls

run all tests

```bash
make grade
# Or
./grade-lab-syscall
```

run the grade tests for one assignment

```bash
make GRADEFLAGS=<syscall> grade
./grade-lab-syscall <syscall>

# eg
make GRADEFLAGS=sysinfotest grade
./grade-lab-syscall sysinfotest
```

Notes: Lack answers-syscall.txt file, need to use gdb to retrieve the corresponding question results

## Lab Page tables

run all tests

```bash
make grade
# Or
./grade-lab-pgtbl
```

run the grade tests for one assignment

```bash
./grade-lab-pgtbl pgtbltest
./grade-lab-pgtbl pte printout
```

## Lab Traps

run all tests

```bash
make grade
# Or
./grade-lab-traps
```

run the grade tests for one assignment

```bash
./grade-lab-traps backtrace
./grade-lab-traps alarm
```

**manual test**

backtrace

```bash
make qemu
bttest

# Open another terminal(don't enter qemu), then
addr2line -e kernel/kernel
# Inputting the address output by bttest will convert it to the corresponding function name
```

alarm

```bash
make qemu

alarmtest
usertests -q  # It will take some time
```

Notes: Lack answers-traps.txt file

## Lab Copy on-write

run all tests

```bash
make grade
# Or
./grade-lab-cow
```

manual test

```bash
make qemu
cowtest
usertests -q
```

Notes: usertests failed in manual test

## Lab Multithreading

run all tests

```bash
make grade
# Or
./grade-lab-thread
```

run the grade tests for one assignment

```bash
./grade-lab-thread uthread

./grade-lab-thread ph
./grade-lab-thread ph_safe
./grade-lab-thread ph_fast

./grade-lab-thread barrier
```

**manual test**

switching between threads

```bash
make qemu
uthread
```

Using threads

```bash
make ph
./ph 1
./ph 2
```

Barrier

```bash
make barrier
./barrier 2
```

## Lab network driver

run all tests

```bash
make grade
```

manual test

```bash
make server

# Open another terminal
./grade-lab-net
## Or
make qemu
nettests
```

## Lab Lock

ToDo

## Lab File system

ToDo

## Lab mmap

ToDo
