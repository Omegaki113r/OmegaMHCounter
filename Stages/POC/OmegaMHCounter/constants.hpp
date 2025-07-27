#pragma once

#include <unordered_map>
#include <string_view>

namespace Omega
{
    namespace Paths
    {
        constexpr auto GREAT_SWORD_PATH{"assets/images/weapons/GreatSword.png"};
        constexpr auto SWORD_AND_SHIELD_PATH{"assets/images/weapons/SwordAndShield.png"};
        constexpr auto HAMMER_PATH{"assets/images/weapons/Hammer.png"};
        constexpr auto LANCE_PATH{"assets/images/weapons/Lance.png"};
        constexpr auto SWITCH_AXE_PATH{"assets/images/weapons/SwitchAxe.png"};
        constexpr auto INSECT_GLAIVE_PATH{"assets/images/weapons/InsectGlaive.png"};
        constexpr auto HEAVY_BOWGUN_PATH{"assets/images/weapons/HeavyBowgun.png"};
        constexpr auto LONG_SWORD_PATH{"assets/images/weapons/Longsword.png"}; // LOL.. I FORGOT THIS
        constexpr auto DUAL_BLADES_PATH{"assets/images/weapons/DualBlades.png"};
        constexpr auto HUNTING_HORN_PATH{"assets/images/weapons/HuntingHorn.png"};
        constexpr auto GUNLANCE_PATH{"assets/images/weapons/Gunlance.png"};
        constexpr auto CHARGE_BLADE_PATH{"assets/images/weapons/ChargeBlade.png"};
        constexpr auto LIGHT_BOWGUN_PATH{"assets/images/weapons/LightBowgun.png"};
        constexpr auto BOW_PATH{"assets/images/weapons/Bow.png"};
    }

    enum class TWeapon
    {
        eGREAT_SWORD,
        eSWORD_AND_SHIELD,
        eHAMMER,
        eLANCE,
        eSWITCH_AXE,
        eINSECT_GLAIVE,
        eHEAVY_BOWGUN,
        eLONG_SWORD,
        eDUAL_BLADES,
        eHUNTING_HORN,
        eGUNLANCE,
        eCHARGE_BLADE,
        eLIGHT_BOWGUN,
        eBOW,
    };

    const std::unordered_map<TWeapon, std::string_view> paths{
        {TWeapon::eGREAT_SWORD, Paths::GREAT_SWORD_PATH},
        {TWeapon::eSWORD_AND_SHIELD, Paths::SWORD_AND_SHIELD_PATH},
        {TWeapon::eHAMMER, Paths::HAMMER_PATH},
        {TWeapon::eLANCE, Paths::LANCE_PATH},
        {TWeapon::eSWITCH_AXE, Paths::SWITCH_AXE_PATH},
        {TWeapon::eINSECT_GLAIVE, Paths::INSECT_GLAIVE_PATH},
        {TWeapon::eHEAVY_BOWGUN, Paths::HEAVY_BOWGUN_PATH},
        {TWeapon::eLONG_SWORD, Paths::LONG_SWORD_PATH},
        {TWeapon::eDUAL_BLADES, Paths::DUAL_BLADES_PATH},
        {TWeapon::eHUNTING_HORN, Paths::HUNTING_HORN_PATH},
        {TWeapon::eGUNLANCE, Paths::GUNLANCE_PATH},
        {TWeapon::eCHARGE_BLADE, Paths::CHARGE_BLADE_PATH},
        {TWeapon::eLIGHT_BOWGUN, Paths::LIGHT_BOWGUN_PATH},
        {TWeapon::eBOW, Paths::BOW_PATH},
    };

    const std::unordered_map<TWeapon, std::string_view> names{
        {TWeapon::eGREAT_SWORD, "Great Sword"},
        {TWeapon::eSWORD_AND_SHIELD, "Sword and Shield"},
        {TWeapon::eHAMMER, "Hammer"},
        {TWeapon::eLANCE, "Lance"},
        {TWeapon::eSWITCH_AXE, "Switch Axe"},
        {TWeapon::eINSECT_GLAIVE, "Insect Glaive"},
        {TWeapon::eHEAVY_BOWGUN, "Heavy Bowgun"},
        {TWeapon::eLONG_SWORD, "Long Sword"},
        {TWeapon::eDUAL_BLADES, "Dual Blades"},
        {TWeapon::eHUNTING_HORN, "Hunting Horn"},
        {TWeapon::eGUNLANCE, "Gunlance"},
        {TWeapon::eCHARGE_BLADE, "Charge Blade"},
        {TWeapon::eLIGHT_BOWGUN, "Light Bowgun"},
        {TWeapon::eBOW, "Bow"},
    };
}
