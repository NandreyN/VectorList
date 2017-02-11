#pragma once

namespace CustomVectorComponents
{
	template<class T>
	class Vector
	{
	public:
		class iterator
		{
		public:
			iterator(T* ref) : _data(ref) {}
			iterator operator++() { ++_data; return *this; }
			iterator operator* () const { return *_data; }
			iterator operator->() const { return _data; }
			bool operator==(const iterator& another) const { return this->_data == another._data; }
			bool operator!=(const iterator& another) const { return !this->operator==(another); }

		private:
			T* _data;
		};
	private:

	};
}