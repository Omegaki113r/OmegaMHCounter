#include <cstdio>
#include <array>
#include <string>
#include <format>

#include <raylib.h>

#include "constants.hpp"

struct Weapon
{
    Image image;
    Texture2D texture;
    std::string name;
    size_t current_attempt{1};
    size_t total_allowed{5};
    Weapon(const char* name, const char* path);
};

std::array<Weapon*,14> weapons;

void load_images_and_textures();

int main()
{
//    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(400, 200, "OmegaMHCounter");
    
    load_images_and_textures();
    
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        
        DrawFPS(10, 10);
        
        static int counter{0};
        static int current_weapon{0};
        ++counter;
        if(0 == counter%60)
        {
            current_weapon++;
        }
        
        DrawTextureV(weapons[current_weapon%14]->texture, {20,20}, WHITE);
        DrawText(weapons[current_weapon%14]->name.data(), 100, 100, 32, BLACK);
        
        DrawRectangleV({50,150}, {32,32}, BLACK);
        DrawText("-", 50 + 32/4, 150 + 32/4, 32, WHITE); // i need to look into how to center letters on the box
        const auto mouse_pos{GetMousePosition()};
        if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON) &&
           mouse_pos.x > 50 &&
           mouse_pos.x < 50 + 32 &&
           mouse_pos.y > 150 &&
           mouse_pos.y < 150 + 32
           )
        {
            weapons[current_weapon%14]->current_attempt++;
        }
        
        DrawText(std::format("{} / {}", weapons[current_weapon%14]->current_attempt, weapons[current_weapon%14]->total_allowed).c_str(), 100, 150, 32, RED);
        
        DrawRectangleV({200,150}, {32,32}, BLACK);
        DrawText("+", 200 + 32/4, 150 + 32/4, 32, WHITE); // i need to look into how to center letters on the box
        
        
        EndDrawing();
    }
    CloseWindow();
}


void load_images_and_textures()
{
    weapons[(int)::Omega::TWeapon::eGREAT_SWORD] = new Weapon(::Omega::names.at(::Omega::TWeapon::eGREAT_SWORD).data(),::Omega::paths.at(::Omega::TWeapon::eGREAT_SWORD).data());
    weapons[(int)::Omega::TWeapon::eSWORD_AND_SHIELD] = new Weapon(::Omega::names.at(::Omega::TWeapon::eSWORD_AND_SHIELD).data(),::Omega::paths.at(::Omega::TWeapon::eSWORD_AND_SHIELD).data());
    weapons[(int)::Omega::TWeapon::eHAMMER] = new Weapon(::Omega::names.at(::Omega::TWeapon::eHAMMER).data(),::Omega::paths.at(::Omega::TWeapon::eHAMMER).data());
    weapons[(int)::Omega::TWeapon::eLANCE] = new Weapon(::Omega::names.at(::Omega::TWeapon::eLANCE).data(),::Omega::paths.at(::Omega::TWeapon::eLANCE).data());
    weapons[(int)::Omega::TWeapon::eSWITCH_AXE] = new Weapon(::Omega::names.at(::Omega::TWeapon::eSWITCH_AXE).data(),::Omega::paths.at(::Omega::TWeapon::eSWITCH_AXE).data());
    weapons[(int)::Omega::TWeapon::eINSECT_GLAIVE] = new Weapon(::Omega::names.at(::Omega::TWeapon::eINSECT_GLAIVE).data(),::Omega::paths.at(::Omega::TWeapon::eINSECT_GLAIVE).data());
    weapons[(int)::Omega::TWeapon::eHEAVY_BOWGUN] = new Weapon(::Omega::names.at(::Omega::TWeapon::eHEAVY_BOWGUN).data(),::Omega::paths.at(::Omega::TWeapon::eHEAVY_BOWGUN).data());
    weapons[(int)::Omega::TWeapon::eLONG_SWORD] = new Weapon(::Omega::names.at(::Omega::TWeapon::eLONG_SWORD).data(),::Omega::paths.at(::Omega::TWeapon::eLONG_SWORD).data());
    weapons[(int)::Omega::TWeapon::eDUAL_BLADES] = new Weapon(::Omega::names.at(::Omega::TWeapon::eDUAL_BLADES).data(),::Omega::paths.at(::Omega::TWeapon::eDUAL_BLADES).data());
    weapons[(int)::Omega::TWeapon::eHUNTING_HORN] = new Weapon(::Omega::names.at(::Omega::TWeapon::eHUNTING_HORN).data(),::Omega::paths.at(::Omega::TWeapon::eHUNTING_HORN).data());
    weapons[(int)::Omega::TWeapon::eGUNLANCE] = new Weapon(::Omega::names.at(::Omega::TWeapon::eGUNLANCE).data(),::Omega::paths.at(::Omega::TWeapon::eGUNLANCE).data());
    weapons[(int)::Omega::TWeapon::eCHARGE_BLADE] = new Weapon(::Omega::names.at(::Omega::TWeapon::eCHARGE_BLADE).data(),::Omega::paths.at(::Omega::TWeapon::eCHARGE_BLADE).data());
    weapons[(int)::Omega::TWeapon::eLIGHT_BOWGUN] = new Weapon(::Omega::names.at(::Omega::TWeapon::eLIGHT_BOWGUN).data(),::Omega::paths.at(::Omega::TWeapon::eLIGHT_BOWGUN).data());
    weapons[(int)::Omega::TWeapon::eBOW] = new Weapon(::Omega::names.at(::Omega::TWeapon::eBOW).data(),::Omega::paths.at(::Omega::TWeapon::eBOW).data());
}

Weapon::Weapon(const char* in_name, const char* in_path)
{
    name = in_name;
    image = LoadImage(in_path);
    texture = LoadTextureFromImage(image);
}
