#include "eu_countries.cpp"
#include "geo_coordinate.h"

#include <iostream>
#include <ostream>

using ljankai::EuCountries;
using ljankai::GeoCoordinate;

int main() {
  std::string start_country;
  std::string end_country;
  auto countries = EuCountries();

  std::cout << "Az opciók közül válaszd ki, hogy honnan szeretnél indulni:\n";

  std::map<std::string, GeoCoordinate> euCountries = ljankai::EuCountries();
  for (const auto &[country, geo_coordinate] : countries) {
    std::cout << "- "<< country << std::endl;
  }

  std::cin >> start_country;

  std::cout << "Az opciók közül válaszd ki, hogy hova szeretnél érkezni:\n";

    for (const auto &[country, geo_coordinate] : countries) {
        std::cout << "- "<< country << std::endl;
    }

  std::cin >> end_country;

  auto start = countries.at(start_country);
  auto end = countries.at(end_country);
  auto bearing = start.BearingTo(end).AsDegrees();
  auto distance = start.DistanceTo(end);

  std::cout << "Távolság: " << distance << "km" << std::endl;
  std::cout << "Irány: " << bearing << std::endl;
}
