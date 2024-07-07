#include <iostream>
#include <vector>
#include "Country.h"
#include "geo_coordinate.h"


using ljankai::Country;
using ljankai::GeoCoordinate;

int main() {
  std::cout << "Az opciók közül válaszd ki, hogy honnan szeretnél indulni:\n";
  for (const auto countryData: Country::EuCountries()) {
    std::cout << "- " << countryData.name << "\n";
  }
  std::string start_country;
  std::cin >> start_country;

  bool found = false;
  GeoCoordinate
  for (const auto &countryData:Country::EuCountries()) {
    if (countryData.name == start_country) {
      found = true;
      latitude1 = countryData.latitude;
      longitude1 = countryData.longitude;
      break;
    }
  }

  if (found) {
    std::cout << "Az opciók közül válaszd ki, hogy hova szeretnél menni:\n";
  } else {
    std::cout << "Az euban nem található ilyen ország.\n";
  }

  for (const auto countryData: country.eu_countries) {
    std::cout << "- " << countryData.name << std::endl;
  }

  std::cin >> country.target_country;

  for (const auto &countryData: country.eu_countries) {
    if (countryData.name == country.target_country) {
      found = true;
      latitude2 = countryData.latitude;
      longitude2 = countryData.longitude;
      break;
    }
  }

  double radlatitude1 = convert_radian(latitude1);
  double radlongitude1 = convert_radian(longitude1);
  double radlatitude2 = convert_radian(latitude2);
  double radlongitude2 = convert_radian(longitude2);

  double distance = distance_calculator(radlatitude1, radlongitude1, radlatitude2, radlongitude2);
  double direction = direction_calculator(radlatitude1, radlongitude1, radlatitude2, radlongitude2);

  std::cout << "Távolság: " << distance << "km" << std::endl;
  std::cout << "Irány: " << direction << std::endl;
}
