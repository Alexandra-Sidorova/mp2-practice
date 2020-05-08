#ifndef _TABRECORD_H_
#define _TABRECORD_H_

#include <iostream>

using namespace std;

template<typename TKey, class TData>
class TTabRecord
{
protected:
    TKey key;
    TData* data;

public:
    TTabRecord(TKey _key = {}, TData* _data = nullptr)
    {
        key = _key;
        data = _data;
    }

    TData* GetData() const { return data; }
    TKey GetKey() const { return key; }

    void SetData(TData* _data) { data = _data; }
    void SetKey(const TKey _key) { key = _key; }

    bool operator>(const TTabRecord& _record) const;
    bool operator>=(const TTabRecord& _record) const;
    bool operator<(const TTabRecord& _record) const;
    bool operator<=(const TTabRecord& _record) const;

    template<typename TKey, class TData> friend ostream& operator<<(ostream& _out, const TTabRecord& _record);
};
//------------------------------------------

template<typename TKey, class TData>
bool TTabRecord<TKey, TData>::operator>(const TTabRecord& _record) const
{
    return(key > _record.key);
};

template<typename TKey, class TData>
bool TTabRecord<TKey, TData>::operator>=(const TTabRecord& _record) const
{
    return(key >= _record.key);
};

template<typename TKey, class TData>
bool TTabRecord<TKey, TData>::operator<(const TTabRecord& _record) const
{
    return(key < _record.key);
};

template<typename TKey, class TData>
bool TTabRecord<TKey, TData>::operator<=(const TTabRecord& _record) const
{
    return(key <= _record.key);
};

template<typename TKey, class TData>
ostream& operator<<(ostream& _out, const TTabRecord<TKey, TData>& _record)
{
    _out << "Key: " << _record.GetKey() << "\t Data: " << _record.GetData();

    return _out;
};

#endif