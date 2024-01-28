
template<typename T>
Array<T>::Array(): elements(new T[0]), _size(new std::size_t(0))
{
//Const
}

template<typename T>
Array<T>::Array(const unsigned int n): elements(new T[n]), _size(new std::size_t(n))
{
}

template<typename T>
Array<T>::Array(const Array<T>& src)
{
//Copy Const
	*this = src;
}

template<typename T>
Array<T>::~Array()
{
//Dest
	delete[] elements;
	delete _size;
}

template<typename T>
Array<T>& Array<T>::operator = (const Array<T>& src)
{
	if (this != &src)
	{
		delete[] this->elements;
		delete _size;
		this->elements = new T[src.size()];
		_size = new std::size_t(src.size());
		for (std::size_t i = 0; i < src.size(); i++)
			this->elements[i] = src.elements[i];
	}
	return *this;
}

template<typename T>
std::size_t Array<T>::size() const
{
	return *_size;
}

template<typename T>
T& Array<T>::operator [] (const std::size_t index)
{
	if (index >= *_size)
		throw std::out_of_range("Array Exception -> Index out of bounds");
	return elements[index];
}

template<typename T>
const T& Array<T>::operator [] (const std::size_t index) const
{
	if (index >= *_size)
		throw std::out_of_range("Array Exception -> Index out of bounds");
	return elements[index];
}
