from vehicle import StreetRacer, FormulaOne, Helicopter, Jet
from goalgorithm import GoByDrivingAlgorithm, GoByFlyingAlgorithm, GoByFlyingFastAlgorithm

drive_algorithm = GoByDrivingAlgorithm()
fly_algorithm = GoByFlyingAlgorithm()
flyfast_algorithm = GoByFlyingFastAlgorithm()

streetRacer = StreetRacer()
formulaOne = FormulaOne()
helicopter = Helicopter()
jet = Jet()

streetRacer.setGoAlgorithm(drive_algorithm)
formulaOne.setGoAlgorithm(drive_algorithm)
helicopter.setGoAlgorithm(fly_algorithm)
jet.setGoAlgorithm(flyfast_algorithm)

streetRacer.go()
formulaOne.go()
helicopter.go()
jet.go()

# Jet will taxi down runway
print("Jet taxis down runway")
jet.setGoAlgorithm(drive_algorithm)
jet.go()

# Jet takes off
print("Jet takes off")
jet.setGoAlgorithm(fly_algorithm)
jet.go()

# Jet goes supersonic
print("Jet goes supersonic")
jet.setGoAlgorithm(flyfast_algorithm)
jet.go()