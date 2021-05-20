/*
** EPITECH PROJECT, 2021
** cpp_poolday7_am
** File description:
** Federation_test
*/

#include "../Federation.hpp"
#include <iostream>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(Federation, should_create_uss_ship)
{
    cr_redirect_stdout();
    Federation::Starfleet::Ship ship(100, 20, "Swag", 6);
    cr_assert_stdout_eq_str("The ship USS Swag has been finished.\nIt is 100 m \
in length and 20 m in width.\nIt can go to Warp 6!\n");
}

Test(Federation, should_create_uss_ship_with_torpedo)
{
    cr_redirect_stdout();
    Federation::Starfleet::Ship ship(100, 20, "Swag", 6, 2);
    cr_assert_stdout_eq_str("The ship USS Swag has been finished.\nIt is 100 m \
in length and 20 m in width.\nIt can go to Warp 6!\nWeapons are set: 2 torpedoes \
ready.\n");
}

Test(Federation, should_setup_core_on_uss_ship)
{
    Federation::Starfleet::Ship ship(100, 20, "Swag", 6, -6);
    WarpSystem::QuantumReactor quantum;
    WarpSystem::Core core(&quantum);

    cr_redirect_stdout();
    ship.setupCore(&core);
    ship.checkCore();
    core.checkReactor()->setStability(false);
    ship.checkCore();
    cr_assert_stdout_eq_str("USS Swag: The core is set.\nUSS Swag: The core is \
stable at the time.\nUSS Swag: The core is unstable at the time.\n");
}

Test(Federation, should_move_uss_ship)
{
    Federation::Starfleet::Ship ship(100, 20, "Swag", 6);
    WarpSystem::QuantumReactor quantum;
    WarpSystem::Core core(&quantum);
    bool result;

    ship.setupCore(&core);
    result = ship.move(3, VULCAN);
    cr_assert_eq(result, true);
    result = ship.move(3, VULCAN);
    cr_assert_eq(result, false);
    result = ship.move(9, ROMULUS);
    cr_assert_eq(result, false);
    core.checkReactor()->setStability(false);
    result = ship.move(3, ROMULUS);
    cr_assert_eq(result, false);
    result = ship.move(3);
    cr_assert_eq(result, false);
    core.checkReactor()->setStability(true);
    result = ship.move(9);
    cr_assert_eq(result, false);
    result = ship.move(3);
    cr_assert_eq(result, true);
    core.checkReactor()->setStability(false);
    result = ship.move(BABEL);
    cr_assert_eq(result, false);
    core.checkReactor()->setStability(true);
    result = ship.move(EARTH);
    cr_assert_eq(result, false);
    result = ship.move(VULCAN);
    cr_assert_eq(result, true);
    result = ship.move();
    cr_assert_eq(result, true);
    core.checkReactor()->setStability(false);
    result = ship.move();
    cr_assert_eq(result, false);
}

Test(Federation, should_set_and_get_shield_on_uss_ship)
{
    Federation::Starfleet::Ship ship(100, 20, "Swag", 6);
    int shield;

    ship.setShield(200);
    shield = ship.getShield();
    cr_assert_eq(shield, 200);
}

Test(Federation, should_set_and_get_torpedoes_on_uss_ship)
{
    Federation::Starfleet::Ship ship(100, 20, "Swag", 6, 3);
    int torpedoes;

    torpedoes = ship.getTorpedo();
    cr_assert_eq(torpedoes, 3);
    ship.setTorpedo(8);
    torpedoes = ship.getTorpedo();
    cr_assert_eq(torpedoes, 8);
}

Test(Federation, should_fire_one_torpedo_on_borg)
{
    Federation::Starfleet::Ship ship(100, 20, "Swag", 6, 1);
    Federation::Starfleet::Captain captain("Lionel");
    Borg::Ship borgShip(10, 3);
    WarpSystem::QuantumReactor quantum1;
    WarpSystem::QuantumReactor quantum2;
    WarpSystem::Core coreShip(&quantum1);
    WarpSystem::Core coreBorg(&quantum2);
    int torpedo;
    int borgShield;

    ship.setupCore(&coreShip);
    borgShip.setupCore(&coreBorg);
    ship.promote(&captain);
    torpedo = ship.getTorpedo();
    borgShield = borgShip.getShield();
    cr_assert_eq(torpedo, 1);
    cr_assert_eq(borgShield, 100);
    cr_redirect_stdout();
    ship.fire(&borgShip);
    ship.fire(&borgShip);
    cr_assert_stdout_eq_str("Swag: Firing on target. 0 torpedoes remaining.\n\
Swag: No more torpedo to fire, Lionel!\nSwag: No enough torpedoes to fire, Lionel!\n");
    torpedo = ship.getTorpedo();
    cr_assert_eq(torpedo, 0);
    borgShield = borgShip.getShield();
    cr_assert_eq(borgShield, 50);
}

Test(Federation, should_create_ship)
{
    cr_redirect_stdout();
    Federation::Ship ship(100, 20, "Swaggy");
    cr_assert_stdout_eq_str("The independent ship Swaggy just finished its \
construction.\nIt is 100 m in length and 20 m in width.\n");
}

Test(Federation, should_setup_core_on_ship)
{
    Federation::Ship ship(100, 20, "Swaggy");
    WarpSystem::QuantumReactor quantum;
    WarpSystem::Core core(&quantum);

    cr_redirect_stdout();
    ship.setupCore(&core);
    ship.checkCore();
    ship.getCore()->checkReactor()->setStability(false);
    ship.checkCore();
    cr_assert_stdout_eq_str("Swaggy: The core is set.\nSwaggy: The core is \
stable at the time.\nSwaggy: The core is unstable at the time.\n");
}

Test(Federation, should_move_on_ship)
{
    Federation::Ship ship(100, 20, "Swaggy");
    WarpSystem::QuantumReactor quantum;
    WarpSystem::Core core(&quantum);
    bool result;

    ship.setupCore(&core);
    ship.getCore()->checkReactor()->setStability(false);
    result = ship.move(1, EARTH);
    cr_assert_eq(result, false);
    result = ship.move(1);
    cr_assert_eq(result, false);
    result = ship.move(EARTH);
    cr_assert_eq(result, false);
    result = ship.move();
    cr_assert_eq(result, false);
    ship.getCore()->checkReactor()->setStability(true);
    result = ship.move(2, EARTH);
    cr_assert_eq(result, false);
    result = ship.move(1, VULCAN);
    cr_assert_eq(result, false);
    result = ship.move(1, EARTH);
    cr_assert_eq(result, true);
    result = ship.move(2);
    cr_assert_eq(result, false);
    result = ship.move(1);
    cr_assert_eq(result, true);
    result = ship.move(VULCAN);
    cr_assert_eq(result, false);
    result = ship.move(EARTH);
    cr_assert_eq(result, true);
    result = ship.move();
    cr_assert_eq(result, true);
}

Test(Federation, should_create_captain)
{
    Federation::Starfleet::Captain captain("Michel");
    int age = captain.getAge();
    std::string name = captain.getName();

    cr_assert_eq(age, 40);
    cr_assert_eq(name, "Michel");
    captain.setAge(29);
    age = captain.getAge();
    cr_assert_eq(age, 29);
}

Test(Federation, should_promote_captain_on_uss_ship)
{
    Federation::Starfleet::Ship ship(100, 30, "Swag", 6);
    Federation::Starfleet::Captain captain("Michel");

    cr_redirect_stdout();
    ship.promote(&captain);
    cr_assert_stdout_eq_str("Michel: I'm glad to be the captain of the USS Swag.\n");
}

Test(Federation, should_create_ensign)
{
    cr_redirect_stdout();
    Federation::Starfleet::Ensign ensign("Jacob");
    cr_assert_stdout_eq_str("Ensign Jacob, awaiting orders.\n");
}