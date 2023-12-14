cmd_/home/stud/Desktop/Semesterprojekt/B-CAC/RPI_Master/spi_drv-overlay.dtb := mkdir -p /home/stud/Desktop/Semesterprojekt/B-CAC/RPI_Master/ ; gcc -E -Wp,-MD,/home/stud/Desktop/Semesterprojekt/B-CAC/RPI_Master/.spi_drv-overlay.dtb.d.pre.tmp -nostdinc -I./scripts/dtc/include-prefixes -undef -D__DTS__ -x assembler-with-cpp -o /home/stud/Desktop/Semesterprojekt/B-CAC/RPI_Master/.spi_drv-overlay.dtb.dts.tmp /home/stud/Desktop/Semesterprojekt/B-CAC/RPI_Master/spi_drv-overlay.dts ; ./scripts/dtc/dtc -O dtb -o /home/stud/Desktop/Semesterprojekt/B-CAC/RPI_Master/spi_drv-overlay.dtb -b 0 -i/home/stud/Desktop/Semesterprojekt/B-CAC/RPI_Master/ -i./scripts/dtc/include-prefixes -Wno-unit_address_vs_reg -Wno-unit_address_format -Wno-gpios_property -Wno-avoid_unnecessary_addr_size -Wno-alias_paths -Wno-graph_child_address -Wno-simple_bus_reg -Wno-unique_unit_address -Wno-pci_device_reg  -d /home/stud/Desktop/Semesterprojekt/B-CAC/RPI_Master/.spi_drv-overlay.dtb.d.dtc.tmp /home/stud/Desktop/Semesterprojekt/B-CAC/RPI_Master/.spi_drv-overlay.dtb.dts.tmp ; cat /home/stud/Desktop/Semesterprojekt/B-CAC/RPI_Master/.spi_drv-overlay.dtb.d.pre.tmp /home/stud/Desktop/Semesterprojekt/B-CAC/RPI_Master/.spi_drv-overlay.dtb.d.dtc.tmp > /home/stud/Desktop/Semesterprojekt/B-CAC/RPI_Master/.spi_drv-overlay.dtb.d

source_/home/stud/Desktop/Semesterprojekt/B-CAC/RPI_Master/spi_drv-overlay.dtb := /home/stud/Desktop/Semesterprojekt/B-CAC/RPI_Master/spi_drv-overlay.dts

deps_/home/stud/Desktop/Semesterprojekt/B-CAC/RPI_Master/spi_drv-overlay.dtb := \

/home/stud/Desktop/Semesterprojekt/B-CAC/RPI_Master/spi_drv-overlay.dtb: $(deps_/home/stud/Desktop/Semesterprojekt/B-CAC/RPI_Master/spi_drv-overlay.dtb)

$(deps_/home/stud/Desktop/Semesterprojekt/B-CAC/RPI_Master/spi_drv-overlay.dtb):
