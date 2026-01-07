# linux-experiment
linux-6.6.10 experiment

---
# Interrupt Experiment
- Network Interrupt Handler Test

# Interrupt Experiment 2
- Keyboard Interrupt Handler


### Module Build & Insert Module
```bash
make

sudo insmod keyboard_irq.ko
```

### Test
- other window/terminal
``` bash
sudo dmesg -w
```
