#include <cstdio>
#include <array>
#include <string>
#include <format>

#include <raylib.h>

#include "constants.hpp"
#include "container/container.hpp"
#include "label/label.hpp"
#include "button/button.hpp"

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
    InitWindow(325, 102, "OmegaMHCounter"); // lazy to calculate in head :-)
    
    load_images_and_textures();
    
    SetTargetFPS(60);
    
    const auto default_padding{10.0f};
    
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        
        const auto screen_width{GetScreenWidth()};
        const auto screen_height{GetScreenHeight()};
        
        auto panel{
            ::Omega::Widget::Container()
                .size({(float)weapons[0]->texture.height, (float)weapons[0]->texture.height})
                .position({default_padding,default_padding})
                .color({48,48,48,255})
        };
        panel.draw();
        
        DrawTextureV(weapons[0]->texture, {default_padding,default_padding}, WHITE);
        
        auto weapon_label{
            ::Omega::Widget::Label()
                .text(weapons[0]->name.data())
                .position({panel.m_position.x + weapons[0]->texture.width + default_padding,default_padding})
                .font_size(31)
                .color(BLACK)
        };
        weapon_label.draw();
        
        auto neg_button{
            ::Omega::Widget::Button()
                .position({panel.m_position.x + weapons[0]->texture.width + default_padding, default_padding + weapon_label.m_font_size + default_padding})
                .size({31,31})
                .background_color(BLACK)
                .text("-")
                .font_size(31)
                .foreground_color(WHITE)
        };
        neg_button.draw();
        
        auto counter_label{
            ::Omega::Widget::Label()
                .position({neg_button.m_container.m_position.x + neg_button.m_container.m_size.x + default_padding, default_padding + weapon_label.m_font_size + default_padding})
                .font_size(31)
                .text(std::format("{} / {}", weapons[0]->current_attempt, weapons[0]->total_allowed))
                .color(RED)
        };
        counter_label.draw();
        
        auto pos_button{
            ::Omega::Widget::Button()
                .position({counter_label.m_position.x + counter_label.get_measured_size().x + default_padding,counter_label.m_position.y})
                .size({32,32})
                .background_color(BLACK)
                .text("+")
                .font_size(32)
                .foreground_color(WHITE)
        };
        pos_button.draw();
        
        // 72 - 10 = 62 => 62 / 2 = 31
        
//        DrawFPS(10, 10);
//        
//        static int counter{0};
//        static int current_weapon{0};
//        ++counter;
//        if(0 == counter%60)
//        {
//            current_weapon++;
//        }
        

      

        /*
            i have no idea at the moment how to handle the button presses in a generic way yet. that i
            will think about and implement that on the next video. maybe i will think/try implment it in a video too. :-)
         */

        const auto mouse_pos{GetMousePosition()};
        if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON) &&
           mouse_pos.x > 50 &&
           mouse_pos.x < 50 + 32 &&
           mouse_pos.y > 150 &&
           mouse_pos.y < 150 + 32
           )
        {
            weapons[0]->current_attempt++;
        }

        

//        DrawText(std::format("{} / {}", weapons[current_weapon%14]->current_attempt, weapons[current_weapon%14]->total_allowed).c_str(), 100, 150, 32, RED);
        
        


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
