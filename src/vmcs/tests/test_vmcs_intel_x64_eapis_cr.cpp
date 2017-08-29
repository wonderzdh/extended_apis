//
// Bareflank Extended APIs
//
// Copyright (C) 2015 Assured Information Security, Inc.
// Author: Rian Quinn        <quinnr@ainfosec.com>
// Author: Brendan Kerrigan  <kerriganb@ainfosec.com>
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

#include <test_support.h>
#include <catch/catch.hpp>

using namespace intel_x64;
using namespace vmcs;

#ifdef _HIPPOMOCKS__ENABLE_CFUNC_MOCKING_SUPPORT

TEST_CASE("vmcs_intel_x64_eapis_cr: enable cr0 load hook")
{
    MockRepository mocks;
    setup_mm(mocks);
    auto vmcs = setup_vmcs(mocks);

    vmcs->enable_cr0_load_hook(42ULL, 42ULL);
    CHECK(cr0_guest_host_mask::get() == 42ULL);
    CHECK(cr0_read_shadow::get() == 42ULL);
}

TEST_CASE("vmcs_intel_x64_eapis_cr: disable cr0 load hook")
{
    MockRepository mocks;
    setup_mm(mocks);
    auto vmcs = setup_vmcs(mocks);

    vmcs->disable_cr0_load_hook();
    CHECK(cr0_guest_host_mask::get() == 0ULL);
    CHECK(cr0_read_shadow::get() == 0ULL);
}

TEST_CASE("vmcs_intel_x64_eapis_cr: enable cr3 load hook")
{
    MockRepository mocks;
    setup_mm(mocks);
    auto vmcs = setup_vmcs(mocks);

    vmcs->enable_cr3_load_hook();
    CHECK(primary_processor_based_vm_execution_controls::cr3_load_exiting::is_enabled());
}

TEST_CASE("vmcs_intel_x64_eapis_cr: disable cr3 load hook")
{
    MockRepository mocks;
    setup_mm(mocks);
    auto vmcs = setup_vmcs(mocks);

    vmcs->disable_cr3_load_hook();
    CHECK(primary_processor_based_vm_execution_controls::cr3_load_exiting::is_disabled());
}

TEST_CASE("vmcs_intel_x64_eapis_cr: enable cr3 store hook")
{
    MockRepository mocks;
    setup_mm(mocks);
    auto vmcs = setup_vmcs(mocks);

    vmcs->enable_cr3_store_hook();
    CHECK(primary_processor_based_vm_execution_controls::cr3_store_exiting::is_enabled());
}

TEST_CASE("vmcs_intel_x64_eapis_cr: disable cr3 store hook")
{
    MockRepository mocks;
    setup_mm(mocks);
    auto vmcs = setup_vmcs(mocks);

    vmcs->disable_cr3_store_hook();
    CHECK(primary_processor_based_vm_execution_controls::cr3_store_exiting::is_disabled());
}

TEST_CASE("vmcs_intel_x64_eapis_cr: enable cr4 load hook")
{
    MockRepository mocks;
    setup_mm(mocks);
    auto vmcs = setup_vmcs(mocks);

    vmcs->enable_cr4_load_hook(42ULL, 42ULL);
    CHECK(cr4_guest_host_mask::get() == 42ULL);
    CHECK(cr4_read_shadow::get() == 42ULL);
}

TEST_CASE("vmcs_intel_x64_eapis_cr: disable cr4 load hook")
{
    MockRepository mocks;
    setup_mm(mocks);
    auto vmcs = setup_vmcs(mocks);

    vmcs->disable_cr4_load_hook();
    CHECK(cr4_guest_host_mask::get() == 0ULL);
    CHECK(cr4_read_shadow::get() == 0ULL);
}

TEST_CASE("vmcs_intel_x64_eapis_cr: enable cr8 load hook")
{
    MockRepository mocks;
    setup_mm(mocks);
    auto vmcs = setup_vmcs(mocks);

    vmcs->enable_cr8_load_hook();
    CHECK(primary_processor_based_vm_execution_controls::cr8_load_exiting::is_enabled());
}

TEST_CASE("vmcs_intel_x64_eapis_cr: disable cr8 load hook")
{
    MockRepository mocks;
    setup_mm(mocks);
    auto vmcs = setup_vmcs(mocks);

    vmcs->disable_cr8_load_hook();
    CHECK(primary_processor_based_vm_execution_controls::cr8_load_exiting::is_disabled());
}

TEST_CASE("vmcs_intel_x64_eapis_cr: enable cr8 store hook")
{
    MockRepository mocks;
    setup_mm(mocks);
    auto vmcs = setup_vmcs(mocks);

    vmcs->enable_cr8_store_hook();
    CHECK(primary_processor_based_vm_execution_controls::cr8_store_exiting::is_enabled());
}

TEST_CASE("vmcs_intel_x64_eapis_cr: disable cr8 store hook")
{
    MockRepository mocks;
    setup_mm(mocks);
    auto vmcs = setup_vmcs(mocks);

    vmcs->disable_cr8_store_hook();
    CHECK(primary_processor_based_vm_execution_controls::cr8_store_exiting::is_disabled());
}

#endif