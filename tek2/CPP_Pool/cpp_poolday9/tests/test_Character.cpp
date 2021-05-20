/*
** EPITECH PROJECT, 2021
** cpp_poolday9
** File description:
** test_Character
*/

#include "../Character.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(Character, should_create_character)
{
    int pv = 0;
    int energy = 0;
    int lvl = 0;

    cr_redirect_stdout();
    Character c("Jean", 1);
    cr_assert_stdout_eq_str("Jean Created\n");
    pv = c.getPv();
    energy = c.getPower();
    lvl = c.getLvl();
    cr_assert_eq(pv, 100);
    cr_assert_eq(energy, 100);
    cr_assert_eq(lvl, 1);
    cr_assert_eq(c.Range, Character::CLOSE);
}

Test(Character, should_do_close_attack)
{
    Character c("Jean", 1);
    int energy = 0;
    int damage = 0;

    damage = c.CloseAttack();
    cr_assert_eq(damage, 15);
    c.CloseAttack();
    c.CloseAttack();
    c.CloseAttack();
    c.CloseAttack();
    c.CloseAttack();
    c.CloseAttack();
    c.CloseAttack();
    c.Range = Character::RANGE;
    damage = c.CloseAttack();
    cr_assert_eq(damage, 0);
    c.CloseAttack();
    c.CloseAttack();
    c.CloseAttack();
    damage = c.CloseAttack();
    energy = c.getPower();
    cr_assert_eq(damage, 0);
}

Test(Character, should_do_range_attack)
{
    Character c("Jean", 1);
    int energy = 0;
    int damage = 0;

    damage = c.RangeAttack();
    cr_assert_eq(damage, 10);
    energy = c.getPower();
    cr_assert_eq(energy, 90);
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    damage = c.RangeAttack();
    cr_assert_eq(damage, 0);
}

Test(Character, should_take_damage)
{
    Character c("Jean", 1);
    int pv = 0;

    cr_redirect_stdout();
    c.TakeDamage(10);
    pv = c.getPv();
    cr_assert_eq(pv, 90);
    c.TakeDamage(90);
    cr_assert_stdout_eq_str("Jean takes 10 damage\nJean out of combat\n");
}

Test(Character, should_heal_player)
{
    Character c("Jean", 1);
    int pv = 0;

    c.TakeDamage(10);
    pv = c.getPv();
    cr_assert_eq(pv, 90);
    cr_redirect_stdout();
    c.Heal();
    pv = c.getPv();
    cr_assert_eq(pv, 100);
    cr_assert_stdout_eq_str("Jean takes a potion\n");
}

Test(Character, should_restore_power)
{
    Character c("Jean", 1);
    int energy = 0;

    c.RangeAttack();
    energy = c.getPower();
    cr_assert_eq(energy, 90);
    cr_redirect_stdout();
    c.RestorePower();
    energy = c.getPower();
    cr_assert_eq(energy, 100);
    cr_assert_stdout_eq_str("Jean eats\n");
}