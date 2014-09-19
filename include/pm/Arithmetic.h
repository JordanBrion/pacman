#ifndef ARITHMETIC_H
#define ARITHMETIC_H

namespace Arithmetic {

//!
//! \brief Function to calculate a percentage
//! \param value: The percentage to calculate
//! \param max: The maximum value
//! \return The percentage
//!
template<typename T, typename U>
int valueInPercent( T const& value, U const& max ) {

    return ( (value+0.0f) / max ) * 100;

}

}

#endif /* ARITHMETIC_H */
