using UnrealSharp.Attributes;
using UnrealSharp.Core.Attributes;
using UnrealSharp.Interop;
using UnrealSharp.Core.Marshallers;

namespace UnrealSharp.TeamProject;

[UClass, GeneratedType("PlayerCameraController", "UnrealSharp.TeamProject.PlayerCameraController")]
public partial class APlayerCameraController : UnrealSharp.Engine.APlayerCameraManager
{
    static readonly IntPtr NativeClassPtr;
    static APlayerCameraController()
    {
        NativeClassPtr = UCoreUObjectExporter.CallGetNativeClassFromName(typeof(APlayerCameraController).GetAssemblyName(), "UnrealSharp.TeamProject", "PlayerCameraController");
        IntPtr CameraActorClass_NativeProperty = FPropertyExporter.CallGetNativePropertyFromName(NativeClassPtr, "CameraActorClass");
        CameraActorClass_Offset = FPropertyExporter.CallGetPropertyOffset(CameraActorClass_NativeProperty);
        IntPtr CameraActor_NativeProperty = FPropertyExporter.CallGetNativePropertyFromName(NativeClassPtr, "CameraActor");
        CameraActor_Offset = FPropertyExporter.CallGetPropertyOffset(CameraActor_NativeProperty);
        IntPtr TargetCameraLocation_NativeProperty = FPropertyExporter.CallGetNativePropertyFromName(NativeClassPtr, "TargetCameraLocation");
        TargetCameraLocation_Offset = FPropertyExporter.CallGetPropertyOffset(TargetCameraLocation_NativeProperty);
    }
    
    static int CameraActorClass_Offset;
    
    public TSubclassOf<UnrealSharp.Engine.ACameraActor> CameraActorClass
    {
        get
        {
            return SubclassOfMarshaller<UnrealSharp.Engine.ACameraActor>.FromNative(IntPtr.Add(NativeObject, CameraActorClass_Offset), 0);
        }
    }
    
    
    static int CameraActor_Offset;
    
    public UnrealSharp.Engine.ACameraActor CameraActor
    {
        get
        {
            return ObjectMarshaller<UnrealSharp.Engine.ACameraActor>.FromNative(IntPtr.Add(NativeObject, CameraActor_Offset), 0);
        }
    }
    
    
    static int TargetCameraLocation_Offset;
    
    public UnrealSharp.CoreUObject.FVector TargetCameraLocation
    {
        get
        {
            return BlittableMarshaller<UnrealSharp.CoreUObject.FVector>.FromNative(IntPtr.Add(NativeObject, TargetCameraLocation_Offset), 0);
        }
    }
    
    
}