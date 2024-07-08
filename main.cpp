#include "Country.cpp"
#include "geo_coordinate.h"
#include <iostream>

using ljankai::EuCountries;

int main() {
  std::string start_country;
  std::string end_country;
  auto countries = EuCountries();

  std::cout << "Az opciók közül válaszd ki, hogy honnan szeretnél indulni:\n";
  std::cout << "- " << std::endl;

  std::cin >> start_country;

  std::cout << "Az opciók közül válaszd ki, hogy hova szeretnél érkezni:\n";

  std::cout << "- " << std::endl;

  std::cin >> end_country;

  auto start = countries.at(start_country);
  auto end = countries.at(end_country);
  auto distance = start.BearingTo(end).AsDegrees();
  auto bearing = start.DistanceTo(end);

  std::cout << "Távolság: " << distance << "km" << std::endl;
  std::cout << "Irány: " << bearing << std::endl;
}
