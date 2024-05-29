# The woodworker - a keymap to cut wood

This is an [Ergo-L](https://github.com/Nuclear-Squid/ergol)-based keymap for SZA Voyager keyboard. it includes:
- i3 navigation layer
- VScode keymaps

## Installation

Install a Python environment on your machine and run
```
pip install qmk
```

Then clone this repository locally
```
qmk setup etienne-monier/qmk_firmware -b develop
```

## Configuration (optional)

To define the voyager and this keymap as defaults, execute
```
qmk config user.keyboard=voyager
qmk config user.keymap=woodworker
```

## Compilation

If defaults were not configured, use
```
qmk compile -kb voyager -km woodworker
```

Otherwise, use
```
qmk compile
```

## Flash

If defaults were not configured, use
```
qmk flash -kb voyager -km woodworker
```

Otherwise, use
```
qmk flash
```
