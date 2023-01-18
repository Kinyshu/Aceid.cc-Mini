/*
                ░█████╗░░█████╗░███████╗██╗██████╗░░░░░█████╗░░█████╗░
                ██╔══██╗██╔══██╗██╔════╝██║██╔══██╗░░░██╔══██╗██╔══██╗
                ███████║██║░░╚═╝█████╗░░██║██║░░██║░░░██║░░╚═╝██║░░╚═╝
                ██╔══██║██║░░██╗██╔══╝░░██║██║░░██║░░░██║░░██╗██║░░██╗
                ██║░░██║╚█████╔╝███████╗██║██████╔╝██╗╚█████╔╝╚█████╔╝
                ╚═╝░░╚═╝░╚════╝░╚══════╝╚═╝╚═════╝░╚═╝░╚════╝░░╚════╝░

                  Ｔｈｅ ｃｏｄｅ ｗａｓ ｗｒｉｔｔｅｎ ｂｙ Ｋｉｎｙｓｈｕ

                  Links to Aceid.
                   - Website:	https://aceid.cc/
                   - Telegram:  https://t.me/aceid_cc
                   - VK:		https://vk.me/join/AJQ1dwO39CRYputL5JFysaY6

                  Contacts with Coder.
                   - VK:		https://vk.com/kinyshu
                   - Discord:   Kinyshu#5558

                  Github link:  https://github.com/Kinyshu

                  Donate.
                   - QIWI:      https://qiwi.com/n/KINYSHUACEID

                  Used in the project.
                   - HookLib:	https://github.com/HoShiMin/HookLib
                   - ImGui:		https://github.com/ocornut/imgui
                   - stb_image:	https://github.com/planetack/stb_image
                   - termcolor: https://github.com/ikalnytskyi/termcolor
*/#pragma once

#ifndef IMAGES_HPP
#define IMAGES_HPP

#include "../../bytes/bytes.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "../../includes/stb/stb_image.hpp"

class CImagesManager {
public:

    CImagesManager() { }
    ~CImagesManager() { }

    void init(ID3D11Device* d) {

        this->device = d;

        this->bytes("LOGO", logo, sizeof logo, 220, 38);
        this->bytes("LOGO_SCRIPTS", logo_scripts, sizeof logo_scripts, 220, 38);

        this->bytes("BG_LOGO", bglogo, sizeof bglogo, 200, 200);

        this->bytes("WEAPONS", weapons, sizeof weapons, 32, 32);
        this->bytes("AIMING", aiming, sizeof aiming, 32, 32);
        this->bytes("VISUALS", visuals, sizeof visuals, 32, 32);
    }

    ID3D11ShaderResourceView* get(std::string name) {
        return this->images.find(name)->second;
    }

    void remove(std::string name) {
        this->images.erase(name);
    }

    void update(std::string name, std::string path, int w = 1920, int h = 35) {
        this->remove(name);
        this->path(name, path, w, h);
    }

private:
	ID3D11Device* device;
	std::map< std::string, ID3D11ShaderResourceView* > images;

protected:

    void path(std::string name, std::string path, int width, int height) {

        int x, y;
        byte* data = stbi_load(path.c_str(), &x, &y, 0, 4);
        if (data == 0)
            return;

        this->create(name, data, width, height);
    }

    void bytes(std::string name, byte* bytes, int size, int width, int height) {

        int x, y;
        byte* data = stbi_load_from_memory(bytes, size, &x, &y, 0, 4);
        if (data == 0)
            return;

        this->create(name, data, width, height);
    }

	void create(std::string name, byte* bytes, int width, int height) {

        ID3D11Texture2D* texture = nullptr;

        D3D11_TEXTURE2D_DESC desc;
        memset(&desc, 0, sizeof desc);
        {
            desc.Width = width;
            desc.Height = height;
            desc.MipLevels = 1;
            desc.ArraySize = 1;
            desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
            desc.SampleDesc.Count = 1;
            desc.Usage = D3D11_USAGE_DEFAULT;
            desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
            desc.CPUAccessFlags = 0;
        }

        D3D11_SUBRESOURCE_DATA subResource;
        {
            subResource.pSysMem = bytes;
            subResource.SysMemPitch = desc.Width * 4;
            subResource.SysMemSlicePitch = 0;
        }
        this->device->CreateTexture2D(&desc, &subResource, &texture);

        D3D11_SHADER_RESOURCE_VIEW_DESC viewDesc;
        memset(&viewDesc, 0, sizeof viewDesc);
        {
            viewDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
            viewDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
            viewDesc.Texture2D.MipLevels = desc.MipLevels;
            viewDesc.Texture2D.MostDetailedMip = 0;
        }

        ID3D11ShaderResourceView* shader = nullptr;

        this->device->CreateShaderResourceView(texture, &viewDesc, &shader);
        this->images.insert(std::pair(name, shader));

        texture->Release();
	}
};

#endif // !IMAGES_HPP