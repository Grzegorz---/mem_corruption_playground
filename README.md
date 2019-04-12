# mem_corruption_playground

g++ functions.c gst.c -lstdc++ -g -fsanitize=address -O1 -fno-omit-frame-pointer -fsanitize-address-use-after-scope -lasan && ./a.out

ASAN_OPTIONS=strict_string_checks=1:detect_stack_use_after_return=1:check_initialization_order=1:strict_init_order=1:print_stats=1:print_legend=1:detect_invalid_pointer_pairs=5:dump_instruction_bytes=1:halt_on_error=1:dump_instruction_bytes=1 ./a.out
