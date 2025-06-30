#ifndef QUAnTLIB_DAYCOUNTCONVENTION_H
#define QUAnTLIB_DAYCOUNTCONVENTION_H
#include "date.h"
namespace QuantLib
{
    /**
     * @brief Enum class representing different day count conventions.
     */
    enum class DayCount
    {
        ActualActual,
        Actual360,
        Actual365,
        Thirty360,

    };

    class DayCountConvention
    {
    public:
        static double yearFraction(const Date &start, const Date &end, DayCount convention);
    };
}
#endif // QUAnTLIB_DAYCOUNTCONVENTION_H
