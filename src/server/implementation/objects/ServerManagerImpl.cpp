/* Autogenerated with kurento-module-creator */

#include <gst/gst.h>
#include "ServerInfo.hpp"
#include "MediaPipelineImpl.hpp"
#include "ServerManagerImpl.hpp"
#include <jsonrpc/JsonSerializer.hpp>
#include <KurentoException.hpp>
#include <MediaSet.hpp>

#define GST_CAT_DEFAULT kurento_server_manager_impl
GST_DEBUG_CATEGORY_STATIC (GST_CAT_DEFAULT);
#define GST_DEFAULT_NAME "KurentoServerManagerImpl"

namespace kurento
{

ServerManagerImpl::ServerManagerImpl (const std::shared_ptr<ServerInfo> info,
                                      const boost::property_tree::ptree &config) : MediaObjectImpl (config),
  info (info)
{
}

std::shared_ptr<ServerInfo> ServerManagerImpl::getInfo ()
{
  return info;
}

std::vector<std::shared_ptr<MediaPipeline>> ServerManagerImpl::getPipelines ()
{
  std::vector<std::shared_ptr<MediaPipeline>> ret;

  for (auto it : MediaSet::getMediaSet ()->getPipelines() ) {
    ret.push_back (std::dynamic_pointer_cast <MediaPipeline> (it) );
  }

  return ret;
}

std::vector<std::string> ServerManagerImpl::getSessions ()
{
  return MediaSet::getMediaSet ()->getSessions();
}

ServerManagerImpl::StaticConstructor ServerManagerImpl::staticConstructor;

ServerManagerImpl::StaticConstructor::StaticConstructor()
{
  GST_DEBUG_CATEGORY_INIT (GST_CAT_DEFAULT, GST_DEFAULT_NAME, 0,
                           GST_DEFAULT_NAME);
}

} /* kurento */