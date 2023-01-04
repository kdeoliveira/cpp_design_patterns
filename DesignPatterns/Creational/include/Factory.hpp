#pragma once
#include "Common.hpp"
/*
Objects are generated (new operation) from a factory method which is an implementation of a base interface where other classes that contains similar properties can derive from. This allows the implementation of object pooling, caching or more complex logic when creating objects.

The client calls the factory method which returns a generic/abstract object. Each object should implement their own factory method (through inheritence). 
*/

namespace DesignPatterns {
	namespace Creational {

		// Base/Abstract product
		class Product{
		public:
			virtual ~Product() {}
			virtual std::string Operation() const = 0;
			
		protected:
			Product() = default;
		};

		// Derived product implementation
		class ProductImplementation_A : public Product {
		public:
			std::string Operation() const override {
				return "Operation of Product A";
			}
		};

		class ProductImplementation_B : public Product {
		public:
			std::string Operation() const override {
				return "Operation Product B";
			}
		};

		// Base class containing the business logic required for creating the objects
		// pool, caching, etc may be implemented here
		class Creator{
		protected:
			Creator() = default;
		public:
			virtual ~Creator(){}
			virtual std::unique_ptr<Product> FactoryMethod() const = 0;

			// Perform specific business logic on the object it creates
			std::string GetCurrentOpeartion() const {
				std::unique_ptr<Product> product = this->FactoryMethod();	
				return "GetCurrentOperation() calls -> " + product->Operation();
			}
		};

		class CreatorProduct_A : protected Creator {
		public:
			std::unique_ptr<Product> FactoryMethod() {
				return std::unique_ptr<Product>(new ProductImplementation_A());
			}
		};

		class CreatorProduct_B: protected Creator {
		public:
			std::unique_ptr<Product> FactoryMethod() {
				return std::unique_ptr<Product>(new ProductImplementation_B());
			}
		};

	}
}