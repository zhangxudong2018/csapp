cmake_minimum_required(VERSION 3.25)

set(TRIE_TEST_NAME trie)
set(TRIE_TEST_SOURCE
    algorithm/array.c
    algorithm/hashtable.c
    algorithm/trie.c
    test/test_trie.c)

if (CSAPP_TEST_TRIE)
    message(STATUS "trie test enabled")
    add_compile_options(-DDEBUG_TRIE)
    add_executable(${TRIE_TEST_NAME} ${TRIE_TEST_SOURCE})
endif ()

set(RBT_TEST_NAME rbt)
set(RBT_TEST_SOURCE
        algorithm/rbt.c
        algorithm/bst.c
        common/convert.c
        test/test_rbt.c)

if (CSAPP_TEST_RBT)
    message(STATUS "red-black tree test enabled")
    add_compile_options(-DDEBUG_REDBLACK)
    add_executable(${RBT_TEST_NAME} ${RBT_TEST_SOURCE})
endif ()

set(CONVERT_TEST_NAME convert)
set(CONVERT_TEST_SOURCE
        common/convert.c
        test/test_convert.c)

if (CSAPP_TEST_CONVERT)
    message(STATUS "convert test enabled")
    add_compile_options(-DDEBUG_BST -DDEBUG_STRING2UINT)
    add_executable(${CONVERT_TEST_NAME} ${CONVERT_TEST_SOURCE})
endif ()

set(INST_TEST_NAME test_inst)
set(INST_TEST_SOURCE
        common/convert.c
        algorithm/hashtable.c
        algorithm/array.c
        algorithm/trie.c
        hardware/cpu/inst.c
        test/test_inst.c)

if (CSAPP_TEST_INST)
    message(STATUS "instruction test enabled")
    add_compile_options(-DDEBUG_INSTRUCTION_CYCLE)
    add_executable(${INST_TEST_NAME} ${INST_TEST_SOURCE})
endif ()

set(ISA_TEST_NAME run_isa)
set(ISA_TEST_SOURCE
        common/convert.c
        algorithm/hashtable.c
        algorithm/array.c
        algorithm/trie.c
        hardware/cpu/inst.c
        hardware/cpu/interrupt.c
        hardware/cpu/isa.c
        hardware/cpu/mmu.c
        hardware/memory/dram.c
        hardware/memory/swap.c
        process/pagefault.c
        process/schedule.c
        process/syscall.c
        process/fork.c
        test/test_run_isa.c)

if (CSAPP_TEST_RUN_ISA)
    message(STATUS "Instruction Set Architecture(ISA) test enabled")
    add_compile_options(-DDEBUG_INSTRUCTION_CYCLE -DUSE_NAVIE_VA2PA)
    add_executable(${ISA_TEST_NAME} ${ISA_TEST_SOURCE})
endif ()

set(FORK_TEST_NAME fork)
set(FORK_TEST_SOURCE
        common/convert.c
        algorithm/hashtable.c
        algorithm/array.c
        algorithm/trie.c
        hardware/cpu/inst.c
        hardware/cpu/interrupt.c
        hardware/cpu/isa.c
        hardware/cpu/mmu.c
        hardware/memory/dram.c
        hardware/memory/swap.c
        process/pagefault.c
        process/schedule.c
        process/syscall.c
        process/fork.c
        test/test_fork.c)

if (CSAPP_TEST_FORK)
    message(STATUS "fork test enabled")
    add_compile_options(-DDEBUG_INSTRUCTION_CYCLE -DUSE_PAGETABLE_VA2PA -DUSE_FORK_NAIVE_COPY -DVMA_DEBUG)
    add_executable(${FORK_TEST_NAME} ${FORK_TEST_SOURCE})
endif ()

set(FORK_COW_TEST_NAME fork_cow)
set(FORK_COW_TEST_SOURCE
        common/convert.c
        algorithm/hashtable.c
        algorithm/array.c
        algorithm/trie.c
        algorithm/linkedlist.c
        hardware/cpu/inst.c
        hardware/cpu/interrupt.c
        hardware/cpu/isa.c
        hardware/cpu/mmu.c
        hardware/memory/dram.c
        hardware/memory/swap.c
        process/pagefault.c
        process/schedule.c
        process/syscall.c
        process/process.c
        process/fork.c
        process/vmarea.c
        test/test_fork.c)

if (CSAPP_TEST_FORK_COW)
    message(STATUS "fork_cow test enabled")
    add_compile_options(-DDEBUG_INSTRUCTION_CYCLE -DUSE_PAGETABLE_VA2PA -DUSE_FORK_COW -DVMA_DEBUG)
    add_executable(${FORK_COW_TEST_NAME} ${FORK_COW_TEST_SOURCE})
endif ()

set(PAGE_FAULT_TEST_NAME pgf)
set(PAGE_FAULT_TEST_SOURCE
        common/convert.c
        algorithm/hashtable.c
        algorithm/array.c
        algorithm/trie.c
        algorithm/linkedlist.c
        hardware/cpu/inst.c
        hardware/cpu/interrupt.c
        hardware/cpu/isa.c
        hardware/cpu/mmu.c
        hardware/memory/dram.c
        hardware/memory/swap.c
        process/pagefault.c
        process/schedule.c
        process/syscall.c
        process/process.c
        process/fork.c
        process/vmarea.c
        test/test_pagefault.c)

if (CSAPP_TEST_PAGE_FAULT)
    message(STATUS "page fault test enabled")
    add_compile_options(-DDEBUG_INSTRUCTION_CYCLE -DUSE_PAGETABLE_VA2PA)
    add_executable(${PAGE_FAULT_TEST_NAME} ${PAGE_FAULT_TEST_SOURCE})
endif ()

set(CONTEXT_TEST_NAME ctx)
set(CONTEXT_TEST_SOURCE
        common/convert.c
        algorithm/hashtable.c
        algorithm/array.c
        algorithm/trie.c
        algorithm/linkedlist.c
        hardware/cpu/inst.c
        hardware/cpu/interrupt.c
        hardware/cpu/isa.c
        hardware/cpu/mmu.c
        hardware/memory/dram.c
        hardware/memory/swap.c
        process/pagefault.c
        process/schedule.c
        process/syscall.c
        process/fork.c
        process/process.c
        process/vmarea.c
        test/test_context.c)

if (CSAPP_TEST_CONTEXT)
    message(STATUS "context test enabled")
    add_compile_options(-DDEBUG_INSTRUCTION_CYCLE -DUSE_PAGETABLE_VA2PA)
    add_executable(${CONTEXT_TEST_NAME} ${CONTEXT_TEST_SOURCE})
endif ()