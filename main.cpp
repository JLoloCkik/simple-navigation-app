#include "Country.h"
#include "geo_coordinate.h"
#include <iostream>
#include <vector>

using ljankai::Country;
using ljankai::GeoCoordinate;

int main() {
  std::cout << "Az opciók közül válaszd ki, hogy honnan szeretnél indulni:\n";
  for (const auto CountryData : Country::EuCountries()) {
    std::cout << "- " << CountryData.name << "\n";
  }
  std::string start_country;
  std::cin >> start_country;

  bool found = false;
  for (const auto &CountryData : Country::EuCountries()) {
    if (CountryData.name == start_country) {
      found = true;
      GeoCoordinate start = CountryData.geo_coordinate_;
      break;
    }
  }

  if (found) {
    std::cout << "Az opciók közül válaszd ki, hogy hova szeretnél menni:\n";
  } else {
    std::cout << "Az euban nem található ilyen ország.\n";
  }

  for (const auto CountryData : Country::EuCountries()) {
    std::cout << "- " << CountryData.name << std::endl;
  }
  std::string target_country;
  std::cin >> target_country;

  for (const auto &CountryData : Country::EuCountries()) {
    if (CountryData.name == target_country) {
      found = true;
      GeoCoordinate end = CountryData.geo_coordinate_;
      break;
    }
  }

  double distance = start.BearingTo(end);
  double direction = start.DistanceTo(end);

  std::cout << "Távolság: " << distance << "km" << std::endl;
  std::cout << "Irány: " << direction << std::endl;
}
