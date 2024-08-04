#include "Quotes/quotes.hpp"
#include <fstream>
#include "bsml/shared/BSML.hpp"
#include "bsml/shared/BSML-Lite.hpp"
#include "UnityEngine/GameObject.hpp"
#include "HMUI/Touchable.hpp"
#include "UnityEngine/Vector2.hpp"
#include "UnityEngine/Space.hpp"

namespace CustomMenu::Quotes {
    void LoadQuotes() {
        selectedQuotes = quotes;
    }

    void LoadCustomQuotes() {
        std::string path = Constants::QuotePath;
        std::ifstream file(path);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                customQuotes.push_back(line);
            }
            file.close();
        }
        selectedQuotes = customQuotes;
    }

    std::string GetRandomQuote() {
        if (selectedQuotes.empty()) {
            return "No Quotes Found!";
        }
        return selectedQuotes[rand() % selectedQuotes.size()];
    }

    void EnsureFile() {
        std::string modPath = Constants::ModPath;
        if (!std::filesystem::exists(modPath)) {
            std::filesystem::create_directory(modPath);
        }

        std::string path = Constants::QuotePath;
        if (!std::filesystem::exists(path)) {
            std::ofstream file(path);
            file << "sub to JadenEdits\n";
            file << "sub to BlokzVR\n";
            file << "get a fc today\n";
            file << "C-C-COMBO BREAKER\n";
            file.close();
        }
    }
}
