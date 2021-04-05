# navigationSystem
Navigation System (Core system)

The functionality of the Navigation system is as follows

(1) The Navigation System contains the 3 major components GPS sensor, Route and a Point of Interest Database.

(2) A Route consists of Waypoints and Point of Interests. These can be added to the route using the appropriate add methods in CRoute. Chose the following values for CPOI::m_type enumerator, RESTAURANT, TOURISTIC, GASSTATION, UNIVERSITY

(3) The GPS Sensor functionality getCurrentPosition() is simulated by manually entering a position via the keyboard.

(4) CNavigationSystem::enterRoute(): Add some POI’s and waypoints to route. User may create his own trip.

(5) CNavigationSystem::printRoute(): Print all POI’s and Waypoints of the route.

(6) CNavigationSystem::printDistanceCurPosNextPoi(): Get the current position from the GPS sensor and search for the closest Point of Interest.

(7) CPoiDatabase::getPointerToPoi(string name): Searches for a POI with the provided name and returns a pointer to this POI.

(8) The behavior of the other methods should be pretty obvious.
