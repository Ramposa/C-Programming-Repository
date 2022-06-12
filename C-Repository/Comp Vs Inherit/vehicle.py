class Vehicle:
  def __init__(self):
    pass
  def setGoAlgorithm(self, go_Algorithm):
    self.go_strat = go_Algorithm
  def go(self):
    self.go_strat.go()

class StreetRacer(Vehicle):
  def __init__(self):
    pass

class FormulaOne(Vehicle):
  def __init__(self):
    pass

class Helicopter(Vehicle):
  def __init__(self):
    pass

class Jet(Vehicle):
  def __init__(self):
    pass