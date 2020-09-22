class any
{
public :
    //模板构造函数，参数可以是任意类型，真正的数据保存在content中
    template < typename ValueType>
        any(const ValueType & value): content( new holder<ValueType>(value))
    {
    }
    //析构函数，删除保存数据的content对象
    ~any()
    {
        delete content;
    }
    //一个placeholde对象指针，只想其子类folder的一个实现
    // 即content( new holder<ValueType>(value) )语句
    placeholder * content;
public :
 
    //查询真实数据的类型，拆葙时有用。
    const std::type_info & type() const
    {
        return content ? content->type() : typeid ( void );
    }
    /**一个稻草人，存在好处是没有模板参数，可以直接申明，
     *如： placeholder * content;
     *如果使用子类folder类，则这能用older<Type>
     *content，而申明时Type还不确定
     */
    class placeholder
    {
    public : 
        virtual ~placeholder()
        {
        }
    public :
        virtual const std::type_info & type() const = 0;
        virtual placeholder * clone() const = 0; 
    };
    //真正保存和获取数据的类。
    template < typename ValueType>
        class holder : public placeholder
    {
    public :
        holder(const ValueType & value)
            : held(value)
        {
        }
    public :
        virtual const std::type_info & type() const
        {
            return typeid (ValueType);
        }
 
        virtual placeholder * clone() const
        {
            return new holder(held);
        }
 
    public :
        //真正的数据，就保存在这里
        ValueType held;
    };
};
/**
 *获取content->helder数据的方法。
 *
 */
    template < typename ValueType>
ValueType * any_cast(any * operand)
{
    return operand && operand->type() == typeid (ValueType) ? & static_cast <any::holder<ValueType> *>(operand->content)->held : 0;
}