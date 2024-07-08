#include "Country.h"
#include "geo_coordinate.h"
#include <iostream>
#include <ostream>
#include <vector>

using ljankai::EuCountries;
using ljankai::GeoCoordinate;

int main() {
  std::cout << "Az opciók közül válaszd ki, hogy honnan szeretnél indulni:\n";
  std::string start_country;
  std::string end_country;

  std::cin >> start_country;

  std::cin >> end_country;

  var countries = EuCountries();
  var start = countries.at(start_country);
  var start = countries.at(start_country);
  double distance = start.BearingTo(end);
  double bearing = start.DistanceTo(end);

  std::cout << "Távolság: " << distance << "km" << std::endl;
  std::cout << "Irány: " << bearing << std::endl;
}
