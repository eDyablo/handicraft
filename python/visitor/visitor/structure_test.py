import unittest
from structure import Infrastructure


class Compomnent:
  def __init__(self, id):
    self.id = id

  def accept_visitor(self, visitor):
    visitor.visit_component(self)


class Visitor:
  def __init__(self):
    self.log = []

  def visit_component(self, component):
    self.log.append(component.id)


class InfrastructureTest(unittest.TestCase):
  def setUp(self):
    super().setUp()
    self.infra = Infrastructure()
    
  def test_newly_created_has_no_components(self):
    self.assertEqual(self.infra.components, [])

  def test_adds_components_in_order(self):
    self.infra.add_component(1)
    self.infra.add_component(2)
    self.assertEqual(self.infra.components, [1, 2])

  def test_visits_all_its_components_in_order(self):
    self.infra.add_component(Compomnent(1))
    self.infra.add_component(Compomnent(2))
    self.infra.add_component(Compomnent(3))
    visitor = Visitor()
    self.infra.accept_visitor(visitor)
    self.assertEqual(visitor.log, [1, 2, 3])
