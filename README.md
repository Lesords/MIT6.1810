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

See: [Lab: Xv6 and Unix utilities](https://pdos.csail.mit.edu/6.828/2023/labs/util.html)

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

See: [Lab: System calls](https://pdos.csail.mit.edu/6.828/2023/labs/syscall.html)

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

See: [Lab: page tables](https://pdos.csail.mit.edu/6.828/2023/labs/pgtbl.html)

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

See: [Lab: Traps](https://pdos.csail.mit.edu/6.828/2023/labs/traps.html)

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

See: [Lab: Copy-on-Write Fork for xv6](https://pdos.csail.mit.edu/6.828/2023/labs/cow.html)

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

See: [Lab: Multithreading](https://pdos.csail.mit.edu/6.828/2023/labs/thread.html)

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

See: [Lab: networking](https://pdos.csail.mit.edu/6.828/2023/labs/net.html)

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
