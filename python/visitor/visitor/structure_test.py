import unittest
from structure import Infrastructure

class TestComponent:
  def __init__(self, id):
    self.id = id

  def AcceptVisitor(self, visitor):
    visitor.VisitComponent(self)

class TestVisitor:
  def __init__(self):
    self.log = []

  def VisitComponent(self, component):
    self.log.append(component.id)

class InfrastructureTest(unittest.TestCase):
  def setUp(self):
    super().setUp()
    self.infra = Infrastructure()
    
  def test_newly_created_has_no_components(self):
    self.assertEqual(self.infra.components, [])

  def test_adds_components_in_order(self):
    self.infra.AddComponent(1)
    self.infra.AddComponent(2)
    self.assertEqual(self.infra.components, [1, 2])

  def test_visits_all_its_components_in_order(self):
    self.infra.AddComponent(TestComponent(1))
    self.infra.AddComponent(TestComponent(2))
    self.infra.AddComponent(TestComponent(3))
    visitor = TestVisitor()
    self.infra.Visit(visitor)
    self.assertEqual(visitor.log, [1, 2, 3])
