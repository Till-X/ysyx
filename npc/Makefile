all:
	@echo "Write this Makefile by your self."

VSRC = $(shell find $(./vsrc ) -name "*.v")
CSRC = $(wildcard ./csrc/main.cpp)


sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo $(VSRC)
	verilator -Wno-fatal $(VSRC) $(CSRC) --top-module top --trace --cc --exe 
	make -C obj_dir -f Vtop.mk Vtop

wave: sim
	./obj_dir/Vtop
	gtkwave wave.vcd
	
clean:
	-rm -rf obj_dir *.log *.dmp *.vpd core *.vcd
	
	
include ../Makefile
