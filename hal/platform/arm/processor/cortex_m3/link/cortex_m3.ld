__main_stack_size    = DEFINED(main_stack_size) ? main_stack_size : 1k;
__process_stack_size = DEFINED(process_stack_size) ? process_stack_size : 0;

PROVIDE(__main_stack_size = __main_stack_size);
PROVIDE(__process_stack_size = __process_stack_size);
