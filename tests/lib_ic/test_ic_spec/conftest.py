# Copyright 2026 XMOS LIMITED.
# This Software is subject to the terms of the XMOS Public Licence: Version 1.
from arch_option import add_arch_option, generate_target_tests


def pytest_addoption(parser):
    add_arch_option(parser, choices=["xs3a", "vx4b"])


def pytest_generate_tests(metafunc):
    generate_target_tests(metafunc)
