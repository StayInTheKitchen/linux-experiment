# linux-experiment
linux-6.6.10 experiment

---

# How to build kernel

1. download kernel source tree & extract source tree
2. kernel configuration (use current kernel configuration)
```bash
cp /boot/config-$(uname -r) .config
make olddefconfig
```
3. modify .config
```bash
scripts/config --disable SYSTEM_TRUSTED_KEYS
scripts/config --disable SYSTEM_REVOCATION_KEYS
```

or

comment out 

```bash
# .config
CONFIG_SYSTEM_TRUSTED_KEYS, CONFIG_SYSTEM_REVOCATION_KEYS
```

4. build
```bash
make -j$(nproc) bzImage
```
