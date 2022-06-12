import abc



class GoAlgorithm(object):
  __metaclass__ = abc.ABCMeta

  @abc.abstractmethod
  def go(self): 
    """Required Method"""

class GoByDrivingAlgorithm(GoAlgorithm):
  def go(self): 
    print("Now I'm driving")

class GoByFlyingAlgorithm(GoAlgorithm):
  def go(self): 
    print("Now I'm flying")

class GoByFlyingFastAlgorithm(GoAlgorithm):
  def go(self): 
    print("Now I'm flying fast")