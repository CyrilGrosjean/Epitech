/*
** EPITECH PROJECT, 2021
** cpp_poolday7_am
** File description:
** Borg_test
*/

#include "../Borg.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(Borg, should_create_a_borg_ship)
{
    cr_redirect_stdout();
    Borg::Ship ship(10, -2);
    cr_assert_stdout_eq_str("We are the Borgs. Lower your shields and surrender \
yourselves unconditionally.\nYour biological characteristics and technologies \
will be assimilated.\nResistance is futile.\n");
}

Test(Borg, should_setup_and_check_core)
{
    Borg::Ship ship(10, 3);
    WarpSystem::QuantumReactor quantum;
    WarpSystem::Core core(&quantum);

    ship.setupCore(&core);
    cr_redirect_stdout();
    ship.checkCore();
    core.checkReactor()->setStability(false);
    ship.checkCore();
    cr_assert_stdout_eq_str("Everything is in order.\nCritical failure imminent.\n");
}

Test(Borg, should_check_shields)
{
    Borg::Ship ship(10, 3);
    int shield = ship.getShield();

    cr_assert_eq(shield, 100);
    ship.setShield(30);
    shield = ship.getShield();
    cr_assert_eq(shield, 30);
}

Test(Borg, should_check_weapon_frequency)
{
    Borg::Ship ship(10, 3);
    int weaponFrequency = ship.getWeaponFrequency();

    cr_assert_eq(weaponFrequency, 10);
    ship.setWeaponFrequency(5);
    weaponFrequency = ship.getWeaponFrequency();
    cr_assert_eq(weaponFrequency, 5);
}

Test(Borg, should_check_repair)
{
    Borg::Ship ship(10, 3);
    int repair = ship.getRepair();

    cr_assert_eq(repair, 3);
    ship.setRepair(1);
    repair = ship.getRepair();
    cr_assert_eq(repair, 1);
    cr_redirect_stdout();
    ship.repair();
    ship.repair();
    cr_assert_stdout_eq_str("Begin shield re-initialisation... Done. Awaiting further instructions.\n\
Energy cells depleted, shield weakening.\n");
    repair = ship.getRepair();
    cr_assert_eq(repair, 0);
}

Test(Borg, should_move)
{
    Borg::Ship ship(10, 3);
    WarpSystem::QuantumReactor quantum;
    WarpSystem::Core core(&quantum);
    bool result;

    ship.setupCore(&core);
    core.checkReactor()->setStability(false);
    result = ship.move(3);
    cr_assert_eq(result, false);
    result = ship.move(EARTH);
    cr_assert_eq(result, false);
    result = ship.move();
    cr_assert_eq(result, false);
    result = ship.move(3, EARTH);
    cr_assert_eq(result, false);
    core.checkReactor()->setStability(true);
    result = ship.move(4, UNICOMPLEX);
    cr_assert_eq(result, false);
    result = ship.move(15, EARTH);
    cr_assert_eq(result, false);
    result = ship.move(4, EARTH);
    cr_assert_eq(result, true);
    result = ship.move(16);
    cr_assert_eq(result, false);
    result = ship.move(3);
    cr_assert_eq(result, true);
    result = ship.move(UNICOMPLEX);
    cr_assert_eq(result, false);
    result = ship.move(VULCAN);
    cr_assert_eq(result, true);
    result = ship.move();
    cr_assert_eq(result, true);
}

Test(Borg, should_fire_on_ship)
{
    Federation::Ship ship(100, 30, "Swaggy");
    Borg::Ship borgShip(10, 3);
    WarpSystem::QuantumReactor quantum1;
    WarpSystem::QuantumReactor quantum2;
    WarpSystem::Core coreShip(&quantum1);
    WarpSystem::Core coreBorg(&quantum2);
    bool stability;

    ship.setupCore(&coreShip);
    borgShip.setupCore(&coreBorg);
    stability = ship.getCore()->checkReactor()->isStable();
    cr_assert_eq(stability, true);
    cr_redirect_stdout();
    borgShip.fire(&ship);
    cr_assert_stdout_eq_str("Firing on target with 10GW frequency\n");
    stability = ship.getCore()->checkReactor()->isStable();
    cr_assert_eq(stability, false);
}

Test(Borg, should_fire_on_uss_ship)
{
    Federation::Starfleet::Ship ship(100, 30, "Swag", 6);
    Borg::Ship borgShip(10, 3);
    WarpSystem::QuantumReactor quantum1;
    WarpSystem::QuantumReactor quantum2;
    WarpSystem::Core coreShip(&quantum1);
    WarpSystem::Core coreBorg(&quantum2);
    int shield;

    ship.setupCore(&coreShip);
    borgShip.setupCore(&coreBorg);
    shield = ship.getShield();
    cr_assert_eq(shield, 100);
    cr_redirect_stdout();
    borgShip.fire(&ship);
    cr_assert_stdout_eq_str("Firing on target with 10GW frequency\n");
    shield = ship.getShield();
    cr_assert_eq(shield, 90);
}