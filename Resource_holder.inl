template <typename Identifier, typename Resource>
void Resource_holder<Identifier, Resource>::load(Identifier resource_id, const std::string& filename)
{
    std::unique_ptr<Resource> resource(new Resource());
    if (!resource->loadFromFile(filename))
        throw std::runtime_error("Resource_holder::load Failed to load " + filename);

    insert_resource(resource_id, std::move(resource));
}


template <typename Identifier, typename Resource>
template <typename Parameter>
void Resource_holder<Identifier, Resource>::load(Identifier resource_id, const std::string& filename,
        const Parameter& second_param)
{
    std::unique_ptr<Resource> resource(new Resource());
    if (!resource->loadFromFile(filename, second_param))
        throw std::runtime_error("Resource_holder::load Failed to load" + filename);

    insert_resource(resource_id, std::move(resource));
}

template <typename Identifier, typename Resource>
Resource& Resource_holder<Identifier, Resource>::get(Identifier resource_id)
{
    auto found = resource_map.find(resource_id);
    return *found->second;
}

template <typename Identifier, typename Resource>
const Resource& Resource_holder<Identifier, Resource>::get(Identifier resource_id) const
{
    auto found = resource_map.find(resource_id);
    return *found->second;
}

template <typename Identifier, typename Resource>
void Resource_holder<Identifier, Resource>::insert_resource(Identifier resource_id,
        std::unique_ptr<Resource> resource)
{
    auto inserted = resource_map.insert(std::make_pair(resource_id, std::move(resource)));
    assert(inserted.second);
}

