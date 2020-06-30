TEMPLATE = subdirs

# add sub projects contained, order is important as we need to compile core-lib first
SUBDIRS += \
    core-lib \
    ui \
    uiq

# explicitly indicates depend on core-lib
ui.depends = core-lib
