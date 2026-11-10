#include "uincampus/saisie.hpp"
#include "uincampus/regles.hpp"
#include <iostream>
#include <limits>

namespace uin {
namespace {
void viderLigne() { std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); }
void afficherInvite(std::string_view invite) { std::cout << invite << " : " << std::flush; }
} // namespace

std::string lireTexte(std::string_view invite) {
  while (true) {
    afficherInvite(invite);
    std::string texte;
    std::getline(std::cin, texte);
    if (!std::cin) {
      std::cin.clear();
      continue;
    }
    if (texte.empty()) {
      std::cout << "Saisie vide, recommencez.\n";
      continue;
    }
    return texte;
  }
}

int lireEntier(std::string_view invite, int min, int max) {
  while (true) {
    afficherInvite(invite);
    int valeur = 0;
    std::cin >> valeur;
    if (!std::cin) {
      std::cin.clear();
      viderLigne();
      std::cout << "Saisie invalide, entrez un entier.\n";
      continue;
    }
    viderLigne();
    if (valeur < min || valeur > max) {
      std::cout << "Valeur hors intervalle [" << min << ", " << max << "].\n";
      continue;
    }
    return valeur;
  }
}

double lireNote(std::string_view invite) {
  while (true) {
    afficherInvite(invite);
    double note = 0.0;
    std::cin >> note;
    if (!std::cin) {
      std::cin.clear();
      viderLigne();
      std::cout << "Saisie invalide, entrez un nombre.\n";
      continue;
    }
    viderLigne();
    if (!estNoteValide(note)) {
      std::cout << "Note hors intervalle [0, 20].\n";
      continue;
    }
    return note;
  }
}
} // namespace uin